/*
** EPITECH PROJECT, 2022
** my_ftp
** File description:
** commands_manager
*/

#include <command_manager.h>
#include <client_manager.h>
#include <client_list.h>

command_list_t *query_command(char const *name, command_list_t *commands)
{
    command_list_t *command = commands;

    while (command != NULL) {
        if (strcmp(name, command->command.command_name) == 0)
            return (command);
        command = command->next;
    }
    return (NULL);
}

void command_quit(char **args, my_ftp_t *ftp, client_list_t *client)
{
    (void) args;
    dprintf(client->client_socket, "221 See you next time.\r\n");
    close_client(ftp, client);
}
