/* 
 * File:   Table_map_event_handler.cpp
 * Author: vkandy
 * 
 * Created on June 26, 2012, 8:35 PM
 */

#include "Table_map_event_handler.h"

Table_map_event_handler::Table_map_event_handler()
{
}

Table_map_event_handler::Table_map_event_handler(const Table_map_event_handler& orig)
{
}

Table_map_event_handler::~Table_map_event_handler()
{
    event_map::iterator iterator;
    for (iterator = map.begin(); iterator != map.end(); ++iterator)
    {
        delete iterator->second;
    }
}

/**
 * Captures a table event before row event.
 * 
 * @param event
 * @return 
 */
mysql::Binary_log_event *Table_map_event_handler::process_event(mysql::Table_map_event *event)
{
    boost::uint64_t table_id = event->table_id;

    if (map.find(table_id) == map.end())
        map.insert(event_pair(table_id, event));

    delete event;
    return 0;
}

