/* 
 * File:   Table_map_event_handler.h
 * Author: vkandy
 *
 * Created on June 26, 2012, 8:35 PM
 */

#ifndef TABLE_MAP_EVENT_HANDLER_H
#define	TABLE_MAP_EVENT_HANDLER_H

typedef std::map<boost::uint64_t, mysql::Table_map_event *> event_map;
typedef std::pair<boost::uint64_t, mysql::Table_map_event *> event_pair;

class Table_map_event_handler
{
public:
    Table_map_event_handler();
    Table_map_event_handler(const Table_map_event_handler& orig);
    virtual ~Table_map_event_handler();

    mysql::Binary_log_event *process_event(mysql::Table_map_event *tm);
private:
    event_map map;
};

#endif	/* TABLE_MAP_EVENT_HANDLER_H */

