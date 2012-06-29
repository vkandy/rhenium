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

    event_map::iterator pair = Base_event_handler::table_map.find(table_id);
    mysql::Table_map_event *table_map_event = pair->second;

    std::string db_name = table_map_event->db_name;
    std::string table_name = table_map_event->table_name;

    mysql::Row_event_set rows(row_event, table_map_event);
    mysql::Row_event_set::iterator iterator = rows.begin();

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
    while (++iterator != rows.end());

    delete row_event;
    return 0;
}

/**
 * Format insert statement.
 * 
 * @param table_name
 * @param fields
 */
void Row_event_handler::on_insert(std::string db_name, std::string table_name, mysql::Row_of_fields &fields)
{
}

/**
 * Format update statement.
 * 
 * @param table_name
 * @param fields
 */
void Row_event_handler::on_update(std::string db_name, std::string table_name, mysql::Row_of_fields &old_fields, mysql::Row_of_fields &new_fields)
{
}

/**
 * Format delete statement.
 * 
 * @param table_name
 * @param fields
 */
void Row_event_handler::on_delete(std::string db_name, std::string table_name, mysql::Row_of_fields &fields)
{
}
