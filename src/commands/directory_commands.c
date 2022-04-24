/*
** EPITECH PROJECT, 2022
** my_ftp
** File description:
** directory_commands
*/

#include <stdlib.h>
#include <unistd.h>
#include <my_utils.h>
#include <command_manager.h>
#include <my_ftp.h>

static int change_directory(char *path, my_ftp_t *ftp, client_list_t *client)
{
    char *current_dir = client->workdir;
    char *target = NULL;
    int total_length = 4;

    total_length += strlen(ftp->path) + strlen(current_dir) + strlen(path);
    target = malloc(total_length);
    if (target == NULL)
        return (0);
    memset(target, 0, total_length);
    append_path(append_path(target, ftp->path), current_dir);
    append_path(target, path);
    client->workdir = realpath(target, NULL);
    free(target);
    client->workdir = retrieve_workdir(ftp->path, client->workdir);
    if (client->workdir == NULL) {
        client->workdir = current_dir;
        return (0);
    }
    free(current_dir);
    return (1);
}

void command_directory_get(char **args, my_ftp_t *ftp, client_list_t *client)
{
    (void) args;
    (void) ftp;
    if (!has_required_power(client, 1))
        return;
    if (strcmp(ftp->path, client->workdir) == 0)
        dprintf(client->client_socket, "257 \"%s\"\r\n", "/");
    else
        dprintf(client->client_socket, "257 \"%s\"\r\n", client->workdir);
}

void command_directory(char **args, my_ftp_t *ftp, client_list_t *client)
{
    (void) ftp;
    if (!has_required_power(client, 1))
        return;
    if (!args[0]) {
        dprintf(client->client_socket, "550 Failed to change directory.\r\n");
        return;
    }
    if (!change_directory(args[0], ftp, client)) {
        dprintf(client->client_socket, "550 Failed to change directory.\r\n");
        return;
    }
    dprintf(client->client_socket, "250 Directory successfully changed.\r\n");
}

void command_directory_up(char **args, my_ftp_t *ftp, client_list_t *client)
{
    (void) args;
    (void) ftp;
    if (!has_required_power(client, 1))
        return;
    if (!change_directory("../", ftp, client)) {
        dprintf(client->client_socket, "550 Failed to change directory.\r\n");
        return;
    }
    dprintf(client->client_socket, "250 Directory successfully changed.\r\n");
}