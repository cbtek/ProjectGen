/*
    CommandLineArgs.cpp
    

*/
//----------------------------------------
//CommandLineArgs.cpp generated by cberry on 02-20-2018 at 02:13:58 PM
//----------------------------------------
#include "CommandLineArgs.h"
#include "StringUtils.h"
#include <iostream>

BEG_NAMESPACE_CBTEK_UTILITY
CommandLineArgs::CommandLineArgs(const std::string &title, int argc, char **argv, bool case_sensitive)
{
    m_title = title;
    m_is_case_sensitive = case_sensitive;
    m_help_requested = false;
    for (size_t a1 = 1; a1 < argc; ++a1)
    {
        std::string arg = std::string(argv[a1]);
        if (m_help_requested == false)
        {
            m_help_requested = (arg == "--help" || arg == "-h");
        }
        m_all_args.push_back(arg);
    }
}

void CommandLineArgs::addSwitch(const std::string &long_arg_switch,
                                const std::string &short_arg_switch,
                                bool required,
                                const std::string &description)
{
    CommandLineArg arg;
    arg.description = description;
    arg.long_switch = long_arg_switch;
    arg.short_switch = short_arg_switch;
    arg.required = required;
    bool exists = false;
    if (m_is_case_sensitive)
    {
        for (size_t a1 = 1; a1 < m_all_args.size();a1+=2)
        {
            if (m_all_args[a1-1] == long_arg_switch ||
                m_all_args[a1-1] == short_arg_switch)
            {
                arg.value = m_all_args[a1];
                exists = true;
            }
        }
    }
    else
    {
        for (size_t a1 = 1; a1 < m_all_args.size();a1+=2)
        {
            if (StringUtils::equals(m_all_args[a1-1],long_arg_switch) ||
                StringUtils::equals(m_all_args[a1-1],short_arg_switch))
            {
                arg.value = m_all_args[a1];
                exists = true;
            }
        }
    }

    m_args.push_back(arg);
    if (!exists && required)
    {
        m_error_messages.push_back("ERROR: The argument " + long_arg_switch + " or " +short_arg_switch + " is required but has not been defined!");
    }
}

std::string CommandLineArgs::value(const std::string &long_or_short_arg) const
{
    if (m_is_case_sensitive)
    {
        for (const auto &arg : m_args)
        {
            if (arg.long_switch == long_or_short_arg ||
                arg.short_switch == long_or_short_arg)
            {
                return arg.value;
            }
        }
    }
    else
    {
        for (const auto &arg : m_args)
        {
            if (StringUtils::equals(arg.long_switch,long_or_short_arg) ||
                StringUtils::equals(arg.short_switch,long_or_short_arg))
            {
                return arg.value;
            }
        }
    }
    return "";
}

bool CommandLineArgs::exists(const std::string &long_or_short_arg) const
{
    if (m_is_case_sensitive)
    {
        for (const auto &arg : m_args)
        {
            if (arg.long_switch == long_or_short_arg ||
                arg.short_switch == long_or_short_arg)
            {
                return true;
            }
        }
    }
    else
    {
        for (const auto &arg : m_args)
        {
            if (StringUtils::equals(arg.long_switch,long_or_short_arg) ||
                StringUtils::equals(arg.short_switch,long_or_short_arg))
            {
                return true;
            }
        }
    }
    return false;
}

bool CommandLineArgs::operator()(const std::string &long_or_short_arg) const
{
    return exists(long_or_short_arg);
}

std::string CommandLineArgs::operator[](const std::string &long_or_short_arg) const
{
    return value(long_or_short_arg);
}

void CommandLineArgs::exec()
{
    std::cerr << std::flush;
    std::cout << std::flush;
    if (m_help_requested)
    {
        printHelp(false);
        exit(0);
    }

    if (m_error_messages.size())
    {
        for (const auto &error_msg : m_error_messages)
        {
            std::cerr << error_msg << std::endl;
        }
        printHelp(true);
        exit(-1);
    }
}

void CommandLineArgs::printHelp(bool is_error)
{
    CommandLineArg help_arg;
    help_arg.short_switch = "-h";
    help_arg.long_switch = "--help";
    help_arg.required = false;
    help_arg.description = "Displays this screen";      
    size_t index = 0;
    if (is_error)
    {
        std::cerr << "//====================================" << std::endl;
        std::cerr << "// " << m_title << std::endl;
        std::cerr << "//====================================" << std::endl;

        for (const auto &arg : m_args)
        {
            std::cerr << arg.toString() << std::endl;
            ++index;
        }
        std::cerr << help_arg.toString() << std::endl;
    }
    else
    {
        std::cout << "//====================================" << std::endl;
        std::cout << "// " << m_title << std::endl;
        std::cout << "//====================================" << std::endl;
        for (const auto &arg : m_args)
        {
            std::cout << arg.toString() << std::endl;
            ++index;
        }
        std::cout << help_arg.toString() << std::endl;
    }
}

void CommandLineArgs::setTitle(const std::string &title)
{
    m_title = title;
}

CommandLineArgs::~CommandLineArgs()
{

}

std::string CommandLineArgs::CommandLineArg::toString(int spaces) const
{
    if (spaces < 0)
    {
        spaces = 0;
    }
    return long_switch + " [" + short_switch + "]: " + StringUtils::repeat(" ",spaces) + description + (required ? " (required)" : " (optional)");
}


END_NAMESPACE_CBTEK_UTILITY
