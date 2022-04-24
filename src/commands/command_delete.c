/*
** EPITECH PROJECT, 2022
** my_ftp
** File description:
** command_delete
*/

#include <stdio.h>
#include <stdlib.h>
#include <my_utils.h>
#include <command_manager.h>
#include <unistd.h>
#include <sys/stat.h>

static int is_file(char *filepath)
{
    struct stat buffer;

    if (access(filepath, F_OK | R_OK) || stat(filepath, &buffer))
        return (0);
    if (S_ISREG(buffer.st_mode) == 0)
        return (0);
    return (1);
}

static void print_delete_file_failed(client_list_t *client)
{
    dprintf(client->client_socket, "550 Delete operation failed.\r\n");
}

static void delete_targeted_file(char *target, client_list_t *client)
{
    char *real_path = NULL;
    char *deleted = "250 The file has been successfully deleted.\r\n";

    real_path = realpath(target, NULL);
    free(target);
    if (real_path == NULL) {
        print_delete_file_failed(client);
        return;
    }
    if (real_path[strlen(real_path) - 1] == '/') {
        free(real_path);
        print_delete_file_failed(client);
        return;
    }
    if (!is_file(real_path) || remove(real_path) == -1)
        dprintf(client->client_socket, "550 Delete operation failed.\r\n");
    else
        dprintf(client->client_socket, "%s", deleted);
    free(real_path);
}

void command_delete(char **args, my_ftp_t *ftp, client_list_t *client)
{
    char *workdir = client->workdir;
    char *path = args[0];
    char *target = NULL;
    int total_length = 4;

    if (path == NULL)
        return (print_delete_file_failed(client));
    total_length += strlen(ftp->path) + strlen(workdir) + strlen(path);
    target = malloc(total_length);
    if (target == NULL)
        return (print_delete_file_failed(client));
    memset(target, 0, total_length);
    append_path(append_path(target, ftp->path), workdir);
    delete_targeted_file(append_path(target, path), client);
}
