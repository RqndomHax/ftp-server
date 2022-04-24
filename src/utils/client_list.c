/*
** EPITECH PROJECT, 2022
** my_ftp
** File description:
** utils
*/

#include <unistd.h>
#include <stdlib.h>
#include <my_utils.h>
#include <stdio.h>

void destroy_clients(client_list_t **list)
{
    client_list_t *current = *list;
    client_list_t *next;

    while (current != NULL) {
        next = current->next;
        dprintf(current->client_socket, "221 Server closed.\r\n");
        close(current->client_socket);
        if (current->workdir != NULL)
            free(current->workdir);
        free(current);
        current = next;
    }
    *list = NULL;
}

client_list_t *add_to_clients(client_list_t **list, int socket, char *dir)
{
    client_list_t *client = NULL;
    client_list_t *to_last = *list;

    client = malloc(sizeof(client_list_t));
    if (client == NULL)
        return (NULL);
    client->client_socket = socket;
    client->id = -1;
    client->workdir = dir;
    client->next = NULL;
    if (*list == NULL) {
        *list = client;
        return (client);
    }
    while (to_last->next != NULL)
        to_last = to_last->next;
    to_last->next = client;
    return (client);
}

void remove_from_clients(client_list_t **list, client_list_t *target)
{
    client_list_t *last = NULL;
    client_list_t *current = *list;

    if (target == NULL)
        return;
    while (current != NULL) {
        if (target != current) {
            last = current;
            current = current->next;
            continue;
        }
        if (last == NULL)
            *list = *list != NULL ? (*list)->next : NULL;
        else
            last->next = current->next;
        if (target->workdir != NULL)
            free(target->workdir);
        free(target);
        return;
    }
}

int clients_size(client_list_t *list)
{
    client_list_t *tmp = list;
    int size = 0;

    if (list == NULL)
        return (size);
    while (tmp != NULL) {
        tmp = tmp->next;
        size++;
    }
    return (size);
}
