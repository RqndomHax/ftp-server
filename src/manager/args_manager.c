/*
** EPITECH PROJECT, 2022
** my_ftp
** File description:
** args_manager
*/

#include <args_manager.h>
#include <string.h>
#include <my_ftp.h>
#include <my_utils.h>

static void default_ftp_values(my_ftp_t *ftp, int port, char *path)
{
    ftp->port = port;
    ftp->socket_fd = -1;
    ftp->server_socket.sin_family = AF_INET;
    ftp->server_socket.sin_addr.s_addr = INADDR_ANY;
    ftp->server_socket.sin_port = htons(port);
    ftp->path = strdup(path);
    ftp->clients = NULL;
    ftp->commands = NULL;
    ftp->is_running = 1;
}

my_ftp_t *initialize_ftp(int argc, char **argv)
{
    my_ftp_t *ftp = NULL;

    if (argc != 3)
        return (NULL);
    if (!is_positive_number(argv[1]))
        return (NULL);
    ftp = malloc(sizeof(my_ftp_t));
    if (ftp == NULL)
        return (NULL);
    default_ftp_values(ftp, atoi(argv[1]), argv[2]);
    retrieve_commands(&ftp->commands);
    return (ftp);
}
