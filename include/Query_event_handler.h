/* 
 * File:   Query_event_handler.h
 * Author: vkandy
 *
 * Created on June 26, 2012, 8:29 PM
 */
#include "basic_content_handler.h"
#include "Base_event_handler.h"

#ifndef QUERY_EVENT_HANDLER_H
#define	QUERY_EVENT_HANDLER_H

class Query_event_handler : public Base_event_handler
{
public:
    Query_event_handler();
    Query_event_handler(const Query_event_handler& orig);
    virtual ~Query_event_handler();

    mysql::Binary_log_event *process_event(mysql::Query_event *ev);
private:

};

#endif	/* QUERY_EVENT_HANDLER_H */
