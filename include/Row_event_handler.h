/* 
 * File:   Row_event_handler.h
 * Author: vkandy
 *
 * Created on June 26, 2012, 8:34 PM
 */
#include "basic_content_handler.h"

#ifndef ROW_EVENT_HANDLER_H
#define	ROW_EVENT_HANDLER_H

class Row_event_handler
{
public:
    Row_event_handler();
    Row_event_handler(const Row_event_handler& orig);
    virtual ~Row_event_handler();
    
    mysql::Binary_log_event *process_event(mysql::Row_event *re);
private:

};

#endif	/* ROW_EVENT_HANDLER_H */
