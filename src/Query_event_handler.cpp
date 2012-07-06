/* 
 * File:   Query_event_handler.cpp
 * Author: vkandy
 * 
 * Created on June 26, 2012, 8:29 PM
 */
#include "Query_event_handler.h"
#include "Rhenium_utils.h"

Query_event_handler::Query_event_handler(zmq::socket_t *socket)
{
    Query_event_handler::publisher = socket;
}

Query_event_handler::~Query_event_handler()
{
    delete Query_event_handler::publisher;
}

/**
 * Captures an updating statement.
 * 
 * @param event
 * @return 
 */
mysql::Binary_log_event *Query_event_handler::process_event(mysql::Query_event *event)
{
    Rhenium_utils::s_send(publisher, event->query);

    return event;
}

