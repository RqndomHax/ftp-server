/*
** EPITECH PROJECT, 2022
** my_utils
** File description:
** unknown_command
*/

#include <stdio.h>
#include <client_list.h>

void unknown_command(client_list_t *client)
{
    char *login_required = "530 Please login with USER and PASS.\r\n";
    char *command_unknown = "500 Unknown command.\r\n";

    if (client->id < 0) {
        dprintf(client->client_socket, "%s", login_required);
        return;
    }
    dprintf(client->client_socket, "%s", command_unknown);
}
