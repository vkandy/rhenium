/* 
 * File:   Row_event_handler.cpp
 * Author: vkandy
 * 
 * Created on June 26, 2012, 8:34 PM
 */

#include "Row_event_handler.h"
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
mysql::Binary_log_event *Row_event_handler::process_event(mysql::Row_event *event)
{
    boost::uint64_t table_id = event->table_id;
    std::vector<uint8_t> row = event->row;

    switch (event->header()->type_code)
    {
    case mysql::WRITE_ROWS_EVENT:
    case mysql::UPDATE_ROWS_EVENT:
    case mysql::DELETE_ROWS_EVENT:
        ;
    }

    delete event;
    return 0;
}