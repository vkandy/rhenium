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
mysql::Binary_log_event *Row_event_handler::process_event(mysql::Row_event *rev)
{
    boost::uint64_t table_id = rev->table_id;

    delete rev;
    return 0;
}