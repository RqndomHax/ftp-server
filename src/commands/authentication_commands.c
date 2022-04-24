/*
** EPITECH PROJECT, 2022
** my_ftp
** File description:
** authentication_commands
*/

#include <command_manager.h>

void command_pass(char **args, my_ftp_t *ftp, client_list_t *client)
{
    char *no_user = "503 Login with user first.\r\n";
    char *already_connected = "230 Already logged in.\r\n";
    char *successfully_logged_in = "230 Login successful.\r\n";

    (void) ftp;
    if (client->id == -1) {
        dprintf(client->client_socket, no_user);
        return;
    }
    if (client->id > 0) {
        dprintf(client->client_socket, already_connected);
        return;
    }
    if (client->id == -11 && !args[0]) {
        client->id = 1;
        dprintf(client->client_socket, successfully_logged_in);
        return;
    }
    dprintf(client->client_socket, "530 Login incorrect.\r\n");
    client->id = -1;
}

void command_user(char **args, my_ftp_t *ftp, client_list_t *client)
{
    char *switch_error = "530 Cannot switch to another user.\r\n";
    char *password_required = "331 Please specify the password.\r\n";

    (void) ftp;
    if (client->id > 0) {
        dprintf(client->client_socket, switch_error);
        return;
    }
    if (args[0] && strcmp("Anonymous", args[0]) == 0)
        client->id = -11;
    else
        client->id = -2;
    dprintf(client->client_socket, password_required);
}
