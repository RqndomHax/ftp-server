/*
** EPITECH PROJECT, 2022
** my_ftp
** File description:
** check_auth_power
*/

#include <command_manager.h>

int has_required_power(client_list_t *client, int required_power)
{
    int socket = client->client_socket;

    if (client->id >= required_power)
        return (1);
    dprintf(socket, "530 Please login with USER and PASS.\r\n");
    return (0);
}
