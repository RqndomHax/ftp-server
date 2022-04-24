/*
** EPITECH PROJECT, 2022
** my_ftp
** File description:
** client_list
*/

#ifndef CLIENT_LIST_H_
    #define CLIENT_LIST_H_

typedef struct client_list_s
{
    int id;
    int is_authenticated;
    int client_socket;
    struct client_list_s *next;
}client_list_t;

void destroy_clients(client_list_t **list);

client_list_t *add_to_clients(client_list_t **list, int client_socket);

void remove_from_clients(client_list_t **list, client_list_t *target);

int clients_size(client_list_t *list);

#endif /* !CLIENT_LIST_H_ */
