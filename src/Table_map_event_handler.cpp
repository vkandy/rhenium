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

    if (table_map.find(table_id) == table_map.end())
    {
        std::cout << table_map.insert(event_pair(table_id, event)).second << std::endl;
    }

    std::cout << "-------------Table map event-----------------" << std::endl;
    std::cout << "Table Id: " << table_id << std::endl;
    std::cout << "DB Name: " << event->db_name << std::endl;
    std::cout << "Table Name: " << event->table_name << std::endl;
    
    event_map::iterator iterator;
    for (iterator = table_map.begin(); iterator != table_map.end(); ++iterator)
    {
        std::cout << "Table Id: " << iterator->second->table_id << std::endl;
        std::cout << "DB Name: " << iterator->second->db_name << std::endl;
        std::cout << "Table Name: " << iterator->second->table_name << std::endl;
    }
    
    std::cout << "-------------Table map event-----------------" << std::endl;

    delete event;
    return 0;
}
