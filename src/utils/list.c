/*
** EPITECH PROJECT, 2022
** my_ftp
** File description:
** utils
*/

#include <my_utils.h>
#include <stdlib.h>

void list_destroy(list_t **list)
{
    list_t *current = *list;
    list_t *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *list = NULL;
}

list_t *list_add(list_t **list, int client_socket)
{
    list_t *client;
    list_t *to_last = *list;

    client = malloc(sizeof(list_t));
    if (client == NULL)
        return (NULL);
    client->client_socket = client_socket;
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


int list_size(list_t *list)
{
    list_t *tmp = list;
    int size = 0;

    if (list == NULL)
        return (size);
    while (tmp != NULL) {
        tmp = tmp->next;
        size++;
    }
    return (size);
}