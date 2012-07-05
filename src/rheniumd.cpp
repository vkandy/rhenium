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

    Glib::ustring url;
    url = Glib::ustring::compose("mysql://%1:%2@%3:%4", username, password, host, port);
    mysql::Binary_log binlog(mysql::system::create_transport(url.data()));

    Table_map_event_handler tmeh;
    Row_event_handler reh(&tmeh);
    Query_event_handler qeh;

    binlog.content_handler_pipeline()->push_back(&tmeh);
    binlog.content_handler_pipeline()->push_back(&reh);
    binlog.content_handler_pipeline()->push_back(&qeh);

    if (binlog.connect())
    {
        std::cerr << "Can't connect to the master" << std::endl;
        return (EXIT_FAILURE);
    }

    zmq::context_t context(1);
    zmq::socket_t sync(context, ZMQ_PULL);
    sync.bind("tcp://*:5564");

    zmq::socket_t publisher(context, ZMQ_PUB);

    uint64_t hwm = 1;
    publisher.setsockopt(ZMQ_HWM, &hwm, sizeof (hwm));

    uint64_t swap = 25000000;
    publisher.setsockopt(ZMQ_SWAP, &swap, sizeof (swap));
    publisher.bind("tcp://*:5565");

    Rhenium_utils::s_recv(sync);

    int update_nbr;
    for (update_nbr = 0; update_nbr < 10; update_nbr++)
    {
        std::ostringstream oss;
        oss << "Update " << update_nbr;
        Rhenium_utils::s_send(publisher, oss.str());
        sleep(1);
    }

    while (true)
    {
        mysql::Binary_log_event *event;
        binlog.wait_for_next_event(&event);
        delete event;
    }

    return EXIT_SUCCESS;
}