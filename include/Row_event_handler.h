/* 
 * File:   Row_event_handler.h
 * Author: vkandy
 *
 * Created on June 26, 2012, 8:34 PM
 */
#include <cstdlib>
#include <iostream>
#include <glibmm-2.4/glibmm/ustring.h>
#include "basic_content_handler.h"
#include "Base_event_handler.h"
#include "Table_map_event_handler.h"
#include "row_of_fields.h"

#ifndef ROW_EVENT_HANDLER_H
#define	ROW_EVENT_HANDLER_H

class Row_event_handler : public Base_event_handler
{
public:
    Row_event_handler();
    Row_event_handler(const Row_event_handler& orig);
    Row_event_handler(Table_map_event_handler *tmeh);
    virtual ~Row_event_handler();

    mysql::Binary_log_event *process_event(mysql::Row_event *re);
    void on_insert(Glib::ustring db_name, Glib::ustring table_name, mysql::Row_of_fields &fields);
    void on_delete(Glib::ustring db_name, Glib::ustring table_name, mysql::Row_of_fields &fields);
    void on_update(Glib::ustring db_name, Glib::ustring table_name, mysql::Row_of_fields &old_fields, mysql::Row_of_fields &new_fields);

protected:
    Table_map_event_handler *table_map_event_handler;
};

#endif	/* ROW_EVENT_HANDLER_H */

