/* 
 * File:   Xid_handler.cpp
 * Author: vkandy
 * 
 * Created on June 26, 2012, 8:36 PM
 */
#include <glibmm-2.4/glibmm/ustring.h>

#include "Xid_handler.h"
#include "Rhenium_utils.h"

Xid_handler::Xid_handler(zmq::socket_t *socket)
{
    Xid_handler::publisher = socket;
}

Xid_handler::~Xid_handler()
{
    delete Xid_handler::publisher;
}

/**
 * Capture commit/rollback events.
 * 
 * @param xid_event
 * @return 
 */
mysql::Binary_log_event *Xid_handler::process_event(mysql::Xid *event)
{
    Glib::ustring msg;
    msg = Glib::ustring::compose("COMMIT /* xid = %1 */", event->xid_id);

    Rhenium_utils::s_send(publisher, msg.data());

    return event;
}
