/* 
 * Starts binary log event listener.
 * 
 * File:   rheniumd.cpp
 * Author: vkandy
 */

#include <cstdlib>
#include <iostream>
#include "binlog_api.h"
#include "Options.h"
#include "Query_event_handler.h"
#include "Table_map_event_handler.h"
#include "Row_event_handler.h"

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

    std::cout << "Host:" << options.get_host() << std::endl;
    std::cout << "Port:" << options.get_port() << std::endl;
    std::cout << "Username:" << options.get_username() << std::endl;
    std::cout << "Password:" << options.get_password() << std::endl;

    mysql::Binary_log binlog(mysql::system::create_transport("mysql://root:root@127.0.0.1:3306"));

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

    while (true)
    {
        mysql::Binary_log_event *event;
        binlog.wait_for_next_event(&event);
        delete event;
    }

    return EXIT_SUCCESS;
}