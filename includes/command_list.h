/*
** EPITECH PROJECT, 2022
** my_ftp
** File description:
** commands_list
*/

#ifndef COMMANDS_LIST_H_
    #define COMMANDS_LIST_H_
    #include "ftp_command.h"

typedef struct command_list_s
{
    command_t command;
    struct command_list_s *next;
}command_list_t;

void destroy_commands(command_list_t **list);

command_list_t *add_to_commands(command_list_t **list, command_t command);

#endif /* !COMMANDS_LIST_H_ */
