/* 
 * File:   Options.h
 * Author: vkandy
 *
 * Created on June 24, 2012, 8:07 PM
 */
#include <glibmm-2.4/glibmm.h>
#include <glibmm-2.4/glibmm/optionentry.h>
#include <glibmm-2.4/glibmm/optiongroup.h>

#ifndef OPTIONS_H
#define	OPTIONS_H

class Options {
public:
    Options();
    Options(const Options& orig);
    virtual ~Options();

    void parse(int argc, char** argv);

    Glib::ustring get_host() {
        return host;
    }

    int get_port() {
        return port;
    }

    Glib::ustring get_username() {
        return username;
    }

    Glib::ustring get_password() {
        return password;
    }

private:
    Glib::ustring host;
    int port;
    Glib::ustring username;
    Glib::ustring password;
};

#endif	/* OPTIONS_H */

