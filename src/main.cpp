/* 
 * File:   main.cpp
 * Author: vkandy
 *
 * Created on June 22, 2012, 10:08 PM
 */

#include <cstdlib>
#include <iostream>
#include "binlog_api.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv)
{

    Binary_log binlog(system::create_transport("mysql://root:smokie1@10.13.10.49:3306"));
    if (binlog.connect())
    {
        fprintf(stderr, "Can't connect to the master.\n");
        return (EXIT_FAILURE);
    }

    if (binlog.set_position(4) != ERR_OK)
    {
        fprintf(stderr, "Can't reposition the binary log reader.\n");
        return (EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}

