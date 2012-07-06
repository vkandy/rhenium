/* 
 * File:   Xid_handler.h
 * Author: vkandy
 *
 * Created on June 26, 2012, 8:36 PM
 */
#include <zmq.hpp>
#include "basic_content_handler.h"
#include "Base_event_handler.h"

#ifndef XID_HANDLER_H
#define	XID_HANDLER_H

class Xid_handler : public Base_event_handler
{
public:
    Xid_handler(zmq::socket_t *socket);
    virtual ~Xid_handler();

    mysql::Binary_log_event *process_event(mysql::Xid *ev);
protected:
    zmq::socket_t *publisher;
};

#endif	/* XID_HANDLER_H */

