/* 
 * File:   Base_event_handler.cpp
 * Author: vkandy
 * 
 * Created on June 28, 2012, 8:54 PM
 */

#include "Base_event_handler.h"
#include "binlog_event.h"

event_map Base_event_handler::table_map;

Base_event_handler::Base_event_handler()
{
}

Base_event_handler::Base_event_handler(const Base_event_handler& orig)
{
}

Base_event_handler::~Base_event_handler()
{
}

/**
 * Any event that isn't captured by handlers is captured here.
 * 
 * @param event
 * @return 
 */
mysql::Binary_log_event *Base_event_handler::process_event(mysql::Binary_log_event *event)
{
    std::cout << event->header()->type_code << std::endl;

    delete event;
    return 0;
}

