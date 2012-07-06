/* 
 * File:   Rhenium_utils.h
 * Author: vkandy
 *
 * Created on July 4, 2012, 10:45 PM
 */
#include <cstdlib>
#include <iostream>
#include <zmq.hpp>

#ifndef RHENIUM_UTILS_H
#define	RHENIUM_UTILS_H

class Rhenium_utils
{
public:
    Rhenium_utils();
    Rhenium_utils(const Rhenium_utils& orig);
    virtual ~Rhenium_utils();

    static bool s_send(zmq::socket_t *socket, const std::string &string)
    {
        zmq::message_t message(string.size());
        memcpy(message.data(), string.data(), string.size());

        bool rc = socket->send(message);
        return (rc);
    }

    static std::string s_recv(zmq::socket_t *socket)
    {
        zmq::message_t message;
        socket->recv(&message);

        return std::string(static_cast<char*> (message.data()), message.size());
    }
private:

};

#endif	/* RHENIUM_UTILS_H */

