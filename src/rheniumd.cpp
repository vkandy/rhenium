/* 
 * Starts binary log event listener.
 * 
 * File:   rheniumd.cpp
 * Author: vkandy
 */

#include <cstdlib>
#include <iostream>
#include <glibmm.h>
#include <zmq.hpp>
#include "binlog_api.h"
#include "Options.h"
#include "Query_event_handler.h"
#include "Table_map_event_handler.h"
#include "Row_event_handler.h"
#include "Xid_handler.h"
#include "Rhenium_utils.h"

/*
 * Starts the server.
 */
int main(int argc, char** argv)
{
    if (argc <= 1)
    {
        std::cerr << "Try --help for usage" << std::endl;
        exit(EXIT_FAILURE);
    }

    Options options;
    options.parse(argc, argv);

    Glib::ustring host = options.get_host();
    int port = options.get_port();
    Glib::ustring username = options.get_username();
    Glib::ustring password = options.get_password();
    int start_position = options.get_start_position();

    zmq::context_t context(1);
    zmq::socket_t sync(context, ZMQ_PULL);
    sync.bind("tcp://*:5564");

    zmq::socket_t publisher(context, ZMQ_PUB);

    uint64_t hwm = 0;
    publisher.setsockopt(ZMQ_HWM, &hwm, sizeof (hwm));

    uint64_t swap = 25000000;
    publisher.setsockopt(ZMQ_SWAP, &swap, sizeof (swap));
    publisher.bind("tcp://*:5565");

    Glib::ustring url;
    url = Glib::ustring::compose("mysql://%1:%2@%3:%4", username, password, host, port);
    mysql::Binary_log binlog(mysql::system::create_transport(url.data()));

    if (start_position > 0)
    {
        //binlog.set_position(start_position);
    }

    Table_map_event_handler tmeh;
    Row_event_handler reh(&tmeh);
    Xid_handler xeh(&publisher);
    Query_event_handler qeh(&publisher);

    binlog.content_handler_pipeline()->push_back(&tmeh);
    binlog.content_handler_pipeline()->push_back(&reh);
    binlog.content_handler_pipeline()->push_back(&xeh);
    binlog.content_handler_pipeline()->push_back(&qeh);

    if (binlog.connect())
    {
        std::cerr << "Can't connect to the master" << std::endl;
        return (EXIT_FAILURE);
    }

    Rhenium_utils::s_recv(&sync);

    while (true)
    {
        mysql::Binary_log_event *event;
        binlog.wait_for_next_event(&event);
        std::cout << event->get_event_type() << std::endl;
        delete event;
    }

    return EXIT_SUCCESS;
}