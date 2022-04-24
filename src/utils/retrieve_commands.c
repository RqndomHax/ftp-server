/*
** EPITECH PROJECT, 2022
** utils
** File description:
** retrieve_commands
*/

#include <command_list.h>
#include <command_manager.h>

void retrieve_commands(command_list_t **commands)
{
    add_to_commands(commands, (command_t) {"QUIT", command_quit});
    add_to_commands(commands, (command_t) {"USER", command_user});
    add_to_commands(commands, (command_t) {"PASS", command_pass});
    add_to_commands(commands, (command_t) {"HELP", command_help});
    add_to_commands(commands, (command_t) {"NOOP", command_noop});
    add_to_commands(commands, (command_t) {"PWD", command_directory_get});
    add_to_commands(commands, (command_t) {"CWD", command_directory});
    add_to_commands(commands, (command_t) {"CDUP", command_directory_up});
}
