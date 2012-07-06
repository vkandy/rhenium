/* 
 * File:   Options.cpp
 * Author: vkandy
 * 
 * Created on June 24, 2012, 8:07 PM
 */
#include <iostream>
#include "Options.h"

Options::Options()
{
}

Options::Options(const Options& orig)
{
}

/**
 * Parses command line options.
 * 
 * @param argc
 * @param argv
 */
void Options::parse(int argc, char** argv)
{
    try
    {
        Glib::OptionContext option_context("- Rhenium Server");
        Glib::OptionGroup option_group("Options", "");

        Glib::OptionEntry option_host;
        option_host.set_short_name('h');
        option_host.set_long_name("host");
        option_host.set_description("Interface address of master [ default = 127.0.0.1 ]");
        option_group.add_entry(option_host, Options::host);

        Glib::OptionEntry option_port;
        option_port.set_short_name('P');
        option_port.set_long_name("port");
        option_port.set_description("Port to receive data on [default = 3306]");
        option_group.add_entry(option_port, Options::port);

        Glib::OptionEntry option_username;
        option_username.set_short_name('u');
        option_username.set_long_name("user");
        option_username.set_description("User for login if not current user");
        option_group.add_entry(option_username, Options::username);

        Glib::OptionEntry option_password;
        option_password.set_short_name('p');
        option_password.set_long_name("password");
        option_password.set_description("Password to use when connecting to server.");
        option_group.add_entry(option_password, Options::password);

        Glib::OptionEntry option_position;
        option_position.set_short_name('j');
        option_position.set_long_name("start-position");
        option_position.set_description("Start reading the binary log at the first event having a position equal to or greater than the argument");
        option_group.add_entry(option_position, Options::start_position);

        option_context.set_help_enabled(true);
        option_context.set_ignore_unknown_options(false);
        option_context.set_main_group(option_group);

        option_context.parse(argc, argv);
    }
    catch (const Glib::OptionError &e)
    {
        std::cout << e.what() << std::endl;
    }
}

Options::~Options()
{
}

