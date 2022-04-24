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

void command_unimplemented(char **args, my_ftp_t *ftp, client_list_t *client)
{
    (void) ftp;
    (void) args;
    if (!has_required_power(client, 1))
        return;
    dprintf(client->client_socket, "502 command not implemented.\r\n");
}

void command_help(char **args, my_ftp_t *ftp, client_list_t *client)
{
    int socket = client->client_socket;

    (void) args;
    (void) ftp;
    if (!has_required_power(client, 1))
        return;
    dprintf(socket, "214-The following commands are recognized.\n" \
            " ABOR ACCT ALLO APPE CDUP CWD  DELE EPRT EPSV FEAT HELP " \
            "LIST MDTM MKD\n MODE NLST NOOP OPTS PASS PASV PORT PWD  " \
            "QUIT REIN REST RETR RMD  RNFR\n RNTO SITE SIZE SMNT STAT " \
            "STOR STOU STRU SYST TYPE USER XCUP XCWD XMKD \n" \
            " XPWD XRMD\r\n");
    dprintf(client->client_socket, "214 Help OK.\r\n");

}

void command_quit(char **args, my_ftp_t *ftp, client_list_t *client)
{
    (void) args;
    dprintf(client->client_socket, "221 See you next time.\r\n");
    close_client(ftp, client);
}
