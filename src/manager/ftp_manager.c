/*
** EPITECH PROJECT, 2022
** my_ftp
** File description:
** ftp_manager
*/

#include <ftp_manager.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void destroy_ftp(my_ftp_t *ftp)
{
    if (ftp->socket_fd != -1)
        shutdown(ftp->socket_fd, SHUT_RDWR);
    if (ftp->path != NULL)
        free(ftp->path);
    free(ftp);
}

int initialize_server(my_ftp_t *ftp)
{
    struct sockaddr_in server;
    int bind_result = -1;

    ftp->socket_fd = socket(AF_INET , SOCK_STREAM , 0);

    if (ftp->socket_fd == -1)
        return (0);
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = ftp->port;
    bind_result = bind(ftp->socket_fd, (struct sockaddr *)&server, sizeof(server));
    if (bind_result < 0)
        return (0);
    return (1);
}

void run_ftp(my_ftp_t *ftp)
{
    (void) ftp;
}
