/* 
 * File:   Rotate_event_handler.h
 * Author: vkandy
 *
 * Created on June 27, 2012, 1:01 AM
 */
#include "basic_content_handler.h"

#ifndef ROTATE_EVENT_HANDLER_H
#define	ROTATE_EVENT_HANDLER_H

class Rotate_event_handler
{
public:
    Rotate_event_handler();
    Rotate_event_handler(const Rotate_event_handler& orig);
    virtual ~Rotate_event_handler();

    mysql::Binary_log_event *process_event(mysql::Rotate_event *ev);
private:

};

#endif	/* ROTATE_EVENT_HANDLER_H */

