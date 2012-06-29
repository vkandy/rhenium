/* 
 * File:   Base_event_handler.h
 * Author: vkandy
 *
 * Created on June 28, 2012, 8:54 PM
 */
#include "basic_content_handler.h"

#ifndef BASE_EVENT_HANDLER_H
#define	BASE_EVENT_HANDLER_H

typedef std::map<boost::uint64_t, mysql::Table_map_event *> event_map;
typedef std::pair<boost::uint64_t, mysql::Table_map_event *> event_pair;

class Base_event_handler : public mysql::Content_handler
{
public:
    Base_event_handler();
    Base_event_handler(const Base_event_handler& orig);
    virtual ~Base_event_handler();

    mysql::Binary_log_event *process_event(mysql::Binary_log_event *event);

protected:
    static event_map table_map;

private:

};

#endif	/* BASE_EVENT_HANDLER_H */

