/*
** EPITECH PROJECT, 2022
** my_ftp
** File description:
** command_noop
*/

#include <command_manager.h>

void command_noop(char **args, my_ftp_t *ftp, client_list_t *client)
{
    char *noop_result = "200 NOOP ok.\r\n";

    (void) args;
    (void) ftp;
    if (!has_required_power(client, 1))
        return;
    dprintf(client->client_socket, "%s", noop_result);
}
