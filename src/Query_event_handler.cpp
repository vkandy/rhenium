/* 
 * File:   Query_event_handler.cpp
 * Author: vkandy
 * 
 * Created on June 26, 2012, 8:29 PM
 */
#include "Query_event_handler.h"

Query_event_handler::Query_event_handler()
{
}

Query_event_handler::Query_event_handler(const Query_event_handler& orig)
{
}

Query_event_handler::~Query_event_handler()
{
}

/**
 * Captures an updating statement.
 * 
 * @param event
 * @return 
 */
mysql::Binary_log_event *Query_event_handler::process_event(mysql::Query_event *event)
{
    std::cout << event->query << std::endl;
    delete event;
    return 0;
}

