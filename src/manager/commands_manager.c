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

void command_pass(char **args, my_ftp_t *ftp, client_list_t *client)
{
    (void) ftp;
    if (client->id == -1) {
        dprintf(client->client_socket, "503 Login with user first.\r\n");
        return;
    }
    if (client->id > 0) {
        dprintf(client->client_socket, "230 Already logged in.\r\n");
        return;
    }
    if (client->id == -11 && !args[0]) {
        client->id = 1;
        dprintf(client->client_socket, "230 Login successful.\r\n");
        return;
    }
    dprintf(client->client_socket, "530 Login incorrect.\r\n");
    client->id = -1;
}

void command_user(char **args, my_ftp_t *ftp, client_list_t *client)
{
    (void) ftp;
    if (client->id > 0) {
        dprintf(client->client_socket, "530 Cannot switch to another user.\r\n");
        return;
    }
    if (args[0] && strcmp("Anonymous", args[0]) == 0)
        client->id = -11;
    else
        client->id = -2;
    dprintf(client->client_socket, "331 Please specify the password.\r\n");
}
