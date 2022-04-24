/*
** EPITECH PROJECT, 2022
** utils
** File description:
** retrieve_client_socket
*/

#include <client_manager.h>
#include <stdlib.h>

int retrieve_client_socket(my_ftp_t *ftp)
{
    struct sockaddr_in *serv = &ftp->server_socket;
    int serv_size = 0;
    socklen_t *sock_length = NULL;
    int fd = ftp->socket_fd;

    serv_size = sizeof(ftp->server_socket);
    sock_length = (socklen_t *) &serv_size;
    return (accept(fd, (struct sockaddr *restrict) serv, sock_length));
}
