/*
** EPITECH PROJECT, 2022
** my_ftp
** File description:
** client_manager
*/

#include <stdlib.h>
#include <my_utils.h>
#include <client_manager.h>

static int retrieve_client_socket(my_ftp_t *ftp)
{
    struct sockaddr_in *serv = &ftp->server_socket;
    int serv_size = 0;
    socklen_t *sock_length = NULL;
    int fd = ftp->socket_fd;

    serv_size = sizeof(ftp->server_socket);
    sock_length = (socklen_t *) &serv_size;
    return (accept(fd, (struct sockaddr *restrict) serv, sock_length));
}

void retrieve_new_client(my_ftp_t *ftp)
{
    int client_socket = -1;

    if (FD_ISSET(ftp->socket_fd, &ftp->readfds) == 0)
        return;
    client_socket = retrieve_client_socket(ftp);
    if (client_socket < 0) {
        print_error("Could not bind new client socket.");
        return;
    }
    list_add(&ftp->clients, client_socket);
}
