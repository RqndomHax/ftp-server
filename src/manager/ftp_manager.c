/*
** EPITECH PROJECT, 2022
** my_ftp
** File description:
** ftp_manager
*/

#include <ftp_manager.h>
#include <client_manager.h>
#include <my_utils.h>
#include <client_list.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void destroy_ftp(my_ftp_t *ftp)
{
    if (ftp->socket_fd != -1)
        shutdown(ftp->socket_fd, SHUT_RDWR);
    if (ftp->path != NULL)
        free(ftp->path);
    destroy_clients(&ftp->clients);
    destroy_commands(&ftp->commands);
    free(ftp);
}

int initialize_server(my_ftp_t *ftp)
{
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
    ftp->highest_socket = ftp->socket_fd;
    add_clients(ftp);
    select(ftp->highest_socket + 1, &ftp->readfds, NULL, NULL, NULL);
    retrieve_new_client(ftp);
    check_on_clients(ftp);
    if (ftp->is_running)
        loop_ftp(ftp);
}

void run_ftp(my_ftp_t *ftp)
{
    change_running_state(ftp);
    signal(SIGINT, signal_handler);
    if (listen(ftp->socket_fd, 3) < 0)
        return;
    loop_ftp(ftp);
}
