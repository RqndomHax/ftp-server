/*
** EPITECH PROJECT, 2022
** my_ftp
** File description:
** client_manager
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <my_utils.h>
#include <client_manager.h>
#include <command_manager.h>

void add_clients(my_ftp_t *ftp)
{
    client_list_t *current = ftp->clients;

    for (; current; current = current->next) {
        if (current->client_socket <= 0)
            continue;
        FD_SET(current->client_socket, &ftp->readfds);
        if (current->client_socket > ftp->highest_socket)
            ftp->highest_socket = current->client_socket;
    }
}

void close_client(my_ftp_t *ftp, client_list_t *client)
{
    close(client->client_socket);
    remove_from_clients(&ftp->clients, client);
}

static void check_client(my_ftp_t *ftp, client_list_t *client)
{
    command_list_t *command;
    char **raw_command;
    char buffer[1025];
    int read_return = 0;

    read_return = read(client->client_socket, buffer, 1024);
    if (read_return == 0)
        return (close_client(ftp, client));
    raw_command = my_str_to_word_array(buffer, " ");
    if (raw_command == NULL)
        return;
    command = query_command(raw_command[0], ftp->commands);
    if (command != NULL)
        command->command.ptr(&raw_command[1], ftp, client);
    clear_array(raw_command);
}

void check_on_clients(my_ftp_t *ftp)
{
    client_list_t *tmp;
    client_list_t *current = ftp->clients;

    while (current != NULL) {
        if (FD_ISSET(current->client_socket, &ftp->readfds) == 0) {
            current = current->next;
            continue;
        }   
        tmp = current;
        current = current->next;
        check_client(ftp, tmp);
    }
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
    add_to_clients(&ftp->clients, client_socket);
    dprintf(client_socket, "220 Welcome to the RqndomFTP, have fun!\n");
}
