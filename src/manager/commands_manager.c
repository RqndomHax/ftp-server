/*
** EPITECH PROJECT, 2022
** my_ftp
** File description:
** commands_manager
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <command_manager.h>
#include <client_manager.h>
#include <client_list.h>

command_list_t *query_command(char const *command_name, command_list_t *commands)
{
    command_list_t *command = commands;

    while (command != NULL) {
        if (strcmp(command_name, command->command.command_name) == 0)
            return (command);
        command = command->next;
    }
    return (NULL);
}

void command_quit(char **args, my_ftp_t *ftp, client_list_t *client)
{
    (void) args;
    dprintf(client->client_socket, "221 See you next time.\n");
    close_client(ftp, client);
}