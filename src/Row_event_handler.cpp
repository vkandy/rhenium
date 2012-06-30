/* 
 * File:   Row_event_handler.cpp
 * Author: vkandy
 * 
 * Created on June 26, 2012, 8:34 PM
 */
#include "Row_event_handler.h"
#include "Table_map_event_handler.h"
#include "rowset.h"
#include <stdlib.h>
#include <boost/foreach.hpp>

Row_event_handler::Row_event_handler()
{
}

Row_event_handler::Row_event_handler(const Row_event_handler& orig)
{
}

Row_event_handler::~Row_event_handler()
{
    event_map::iterator iterator;
    for (iterator = table_map.begin(); iterator != table_map.end(); ++iterator)
    {
        delete iterator->second;
    }
}

/**
 * Captures an updating statement.
 * 
 * @param event
 * @return 
 */
mysql::Binary_log_event *Row_event_handler::process_event(mysql::Row_event *row_event)
{
    boost::uint64_t table_id = row_event->table_id;
    event_map::iterator pair = table_map.find(table_id);

    std::cout << "-------------Row event-----------------" << std::endl;
    if (pair == table_map.end())
    {
        std::cout << "Table id " << table_id << " was not registered by any preceding table map event" << std::endl;
        return row_event;
    }

    std::cout << "Map size:" << table_map.size() << std::endl;
    event_map::iterator iterator;
    for (iterator = table_map.begin(); iterator != table_map.end(); ++iterator)
    {
        std::cout << "Table Id: " << iterator->second->table_id << std::endl;
        std::cout << "DB Name: " << iterator->second->db_name << std::endl;
        std::cout << "Table Name: " << iterator->second->table_name << std::endl;
    }


    mysql::Table_map_event *table_map_event = pair->second;
    std::ostringstream os;
    os << table_map_event->db_name.size(); //<< '.' << table_map_event->table_name;
    std::cout << os.str() << std::endl;

    // Glib::ustring db_name(table_map_event->db_name);
    // Glib::ustring table_name(table_map_event->table_name);

    mysql::Row_event_set rows(row_event, table_map_event);
    mysql::Row_event_set::iterator iterator = rows.begin();
    /*
        do
        {
            mysql::Row_of_fields fields = *iterator;

            switch (row_event->header()->type_code)
            {
            case mysql::WRITE_ROWS_EVENT:
                on_insert(db_name, table_name, fields);
                break;
            case mysql::DELETE_ROWS_EVENT:
                on_delete(db_name, table_name, fields);
                break;
            case mysql::UPDATE_ROWS_EVENT:
                ++iterator;
                mysql::Row_of_fields new_fields = *iterator;
                on_update(db_name, table_name, fields, new_fields);
                break;
            }
        }
        while (++iterator != rows.end());*/

    std::cout << "-------------Row event-----------------" << std::endl;

    delete row_event;
    return 0;
}

/**
 * Format insert statement.
 * 
 * @param db_name
 * @param table_name
 * @param fields
 */
void Row_event_handler::on_insert(Glib::ustring db_name, Glib::ustring table_name, mysql::Row_of_fields &fields)
{
    std::cout << db_name << "." << table_name << std::endl;
}

/**
 * Format update statement.
 * 
 * @param db_name
 * @param table_name
 * @param fields
 */
void Row_event_handler::on_update(Glib::ustring db_name, Glib::ustring table_name, mysql::Row_of_fields &old_fields, mysql::Row_of_fields &new_fields)
{
    std::cout << db_name << "." << table_name << std::endl;
}

/**
 * Format delete statement.
 * 
 * @param db_name
 * @param table_name
 * @param fields
 */
void Row_event_handler::on_delete(Glib::ustring db_name, Glib::ustring table_name, mysql::Row_of_fields &fields)
{
    std::cout << db_name << "." << table_name << std::endl;
}
