/* 
 * File:   Rotate_event_handler.cpp
 * Author: vkandy
 * 
 * Created on June 27, 2012, 1:01 AM
 */

#include "Rotate_event_handler.h"

Rotate_event_handler::Rotate_event_handler()
{
}

Rotate_event_handler::Rotate_event_handler(const Rotate_event_handler& orig)
{
}

Rotate_event_handler::~Rotate_event_handler()
{
}

/**
 * Captures an updating statement.
 * 
 * @param event
 * @return 
 */
mysql::Binary_log_event *Rotate_event_handler::process_event(mysql::Rotate_event *event)
{
    std::cout << "filename = "
        << event->binlog_file.c_str()
        << " pos = "
        << event->binlog_pos
        << std::endl
        << std::endl;

    delete event;
    return 0;
}

