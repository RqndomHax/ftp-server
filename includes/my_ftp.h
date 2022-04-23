/*
** EPITECH PROJECT, 2022
** my_ftp
** File description:
** my ftp header
*/

#ifndef MY_FTP_H_
    #define MY_FTP_H_
    #include <arpa/inet.h>
    #include <sys/socket.h>
    #include <sys/select.h>
    #include "ftp_command.h"
    #include "client_list.h"
    #include "command_list.h"

typedef struct my_ftp_s{
    int port;
    int socket_fd;
    char *path;
    struct sockaddr_in server_socket;
    client_list_t *clients;
    command_list_t *commands;
    int is_running;
    fd_set readfds;
    int highest_socket;
}my_ftp_t;

#endif /* !MY_FTP_H_ */
