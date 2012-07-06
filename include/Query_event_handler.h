/* 
 * File:   Query_event_handler.h
 * Author: vkandy
 *
 * Created on June 26, 2012, 8:29 PM
 */
#include <zmq.hpp>
#include "basic_content_handler.h"
#include "Base_event_handler.h"

#ifndef QUERY_EVENT_HANDLER_H
#define	QUERY_EVENT_HANDLER_H

class Query_event_handler : public Base_event_handler
{
public:    
    Query_event_handler(zmq::socket_t *socket);
    virtual ~Query_event_handler();

    mysql::Binary_log_event *process_event(mysql::Query_event *ev);
protected:
    zmq::socket_t *publisher;
};

#endif	/* QUERY_EVENT_HANDLER_H */
