/*
 *
    CommandLineArgs.h        
*/
#pragma once

#include "UtilityCommon.hpp"

#include <vector>
#include <string>

BEG_NAMESPACE_CBTEK_UTILITY
/**
 * @brief The CommandLineArgs class provides a simple way to parse
 * command line args and provide a frontend for CLI apps.
 * It is meant to be used with simple programs and only supports this format:
 * $program -arg1 "arg1 Value" --long-arg-2 "arg2 Value", etc
 * Should you need to support more elaborate use cases, then
 * use a different library or write your own.
 */
class CommandLineArgs 
{
private:
    struct CommandLineArg
    {
        std::string long_switch;
        std::string short_switch;
        std::string description;
        std::string value;
        bool required;
        std::string toString(int spaces = 0) const;

    };
    std::string m_title;
    bool m_is_case_sensitive;
    bool m_help_requested;
    std::vector<CommandLineArg> m_args;
    std::vector<std::string> m_all_args;
    std::vector<std::string> m_error_messages;

public:

    /**
     * @brief CommandLineArgs
     * @param title
     * @param argc
     * @param argv
     * @param case_sensitive
     */
    CommandLineArgs(const std::string &title, int argc, char ** argv, bool case_sensitive = false);
    
    /**
     * @brief addSwitch
     * @param long_arg_switch
     * @param short_arg_switch
     * @param description
     */
    void addSwitch(const std::string &long_arg_switch,
                   const std::string &short_arg_switch,
                   bool required = false,
                   const std::string &description = "");

    /**
     * @brief getValue
     * @param long_or_short_arg
     * @return
     */
    std::string value(const std::string &long_or_short_arg) const;

    /**
     * @brief exists
     * @param long_or_short_arg
     * @return
     */
    bool exists(const std::string &long_or_short_arg) const;

    /**
     * @brief operator ()
     * @param long_or_short_arg
     * @return
     */
    bool operator()(const std::string &long_or_short_arg) const;

    /**
     * @brief operator []
     * @param long_or_short_arg
     * @return
     */
    std::string operator[](const std::string &long_or_short_arg) const;

    /**
     * @brief exec
     */
    void exec();

    /**
     * @brief printHelp
     */
    void printHelp(bool is_error = false);

    /**
     * @brief setTitle
     * @param title
     */
    void setTitle(const std::string &title);

    /**
     * Destructor for this CommandLineArgs
     */
    ~CommandLineArgs();
};
END_NAMESPACE_CBTEK_UTILITY
