/* 
 * File:   Table_map_event_handler.h
 * Author: vkandy
 *
 * Created on June 26, 2012, 8:35 PM
 */
#include "Base_event_handler.h"

#ifndef TABLE_MAP_EVENT_HANDLER_H
#define	TABLE_MAP_EVENT_HANDLER_H

class Table_map_event_handler : public Base_event_handler
{
public:
    Table_map_event_handler();
    Table_map_event_handler(const Table_map_event_handler& orig);
    virtual ~Table_map_event_handler();

    mysql::Binary_log_event *process_event(mysql::Table_map_event *tm);
private:
};

#endif	/* TABLE_MAP_EVENT_HANDLER_H */

