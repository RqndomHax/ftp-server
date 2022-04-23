/*
** EPITECH PROJECT, 2022
** my_ftp
** File description:
** ftp_manager
*/

#include <ftp_manager.h>
#include <client_manager.h>
#include <my_utils.h>
#include <stdlib.h>
#include <stdio.h>

void destroy_ftp(my_ftp_t *ftp)
{
    if (ftp->socket_fd != -1)
        shutdown(ftp->socket_fd, SHUT_RDWR);
    if (ftp->path != NULL)
        free(ftp->path);
    list_destroy(&ftp->clients);
    free(ftp);
}

int initialize_server(my_ftp_t *ftp)
{
    int opt = 1;
    struct sockaddr_in *serv = &ftp->server_socket;
    int bind_result = -1;
    int *fd = &ftp->socket_fd;

    *fd = socket(AF_INET , SOCK_STREAM , 0);
    if (ftp->socket_fd == -1)
        return (0);
    bind_result = bind(*fd, (struct sockaddr *)serv, sizeof(*serv));
    if (bind_result < 0) {
        print_error("Could not bind server socket's port.");
        return (0);
    }
    return (1);
}

static void loop_ftp(my_ftp_t *ftp)
{
    FD_ZERO(&ftp->readfds);
    FD_SET(ftp->socket_fd, &ftp->readfds);
    retrieve_client(ftp);
    if (ftp->is_running)
        run_ftp(ftp);
}

void run_ftp(my_ftp_t *ftp)
{
    if (listen(ftp->socket_fd, 3) < 0)
        return;
    loop_ftp(ftp);
}
