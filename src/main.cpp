/* 
 * Starts binary log event listener.
 * 
 * Author: vkandy
 */

#include <cstdlib>
#include <iostream>
#include "binlog_api.h"

class Query_handler : public Content_handler
{
};

/*
 * 
 */
int main(int argc, char** argv)
{

    mysql::Binary_log binlog(mysql::system::create_transport("mysql://root:root@127.0.0.1:3306"));
    if (binlog.connect())
    {
        fprintf(stderr, "Can't connect to the master.\n");
        return (EXIT_FAILURE);
    }

    fprintf(stdout, "Connected to the master.\n");

    mysql::Binary_log_event *event;
    mysql::Query_event *qe;

    while (true)
    {
        binlog.wait_for_next_event(&event);
        // cout << " at " << event->header()->marker << " event type " << event->get_event_type() << endl;

        switch (event->header()->type_code)
        {
        case mysql::QUERY_EVENT:
            qe = static_cast<mysql::Query_event*> (event);
            std::cout << qe->query << std::endl;
            break;

        default:
            std::cout << " at " << event->header()->marker << " event type " << event->get_event_type() << std::endl;
        }

        delete event;
    }

    return EXIT_SUCCESS;
}

