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

/*
 * Starts the server.
 */
int main(int argc, char** argv)
{
    Options options;
    Query_event_handler qeh;
    mysql::Binary_log_event *event;

    if (argc <= 1)
    {
        std::cerr << "Try --help for usage" << std::endl;
        exit(EXIT_FAILURE);
    }

    options.parse(argc, argv);

    std::cout << "Host:" << options.get_host() << std::endl;
    std::cout << "Port:" << options.get_port() << std::endl;
    std::cout << "Username:" << options.get_username() << std::endl;
    std::cout << "Password:" << options.get_password() << std::endl;

    mysql::Binary_log binlog(mysql::system::create_transport("mysql://root:root@127.0.0.1:3306"));
    binlog.content_handler_pipeline()->push_back(&qeh);

    if (binlog.connect())
    {
        std::cerr << "Can't connect to the master" << std::endl;
        return (EXIT_FAILURE);
    }

    while (true)
    {
        binlog.wait_for_next_event(&event);
        delete event;
    }

    return EXIT_SUCCESS;
}