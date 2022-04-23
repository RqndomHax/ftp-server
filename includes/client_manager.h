/*
** EPITECH PROJECT, 2022
** my_ftp
** File description:
** client_manager
*/

#ifndef CLIENT_MANAGER_H_
    #define CLIENT_MANAGER_H_
    #include "my_ftp.h"

void retrieve_new_client(my_ftp_t *ftp);

void add_clients(my_ftp_t *ftp);

void close_client(my_ftp_t *ftp, client_list_t *client);

void check_on_clients(my_ftp_t *ftp);

#endif /* !CLIENT_MANAGER_H_ */
