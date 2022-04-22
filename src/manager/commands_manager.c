/*
** EPITECH PROJECT, 2022
** my_ftp
** File description:
** commands_manager
*/

#include <command_manager.h>
#include <my_utils.h>

char **parse_command(char *raw_command)
{
    char **command = my_str_to_word_array(raw_command, " ");

    return (command);
}

void execute_command(char **command, command_t *commands)
{
    (void) command;
    (void) commands;
}