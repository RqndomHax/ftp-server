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
}
