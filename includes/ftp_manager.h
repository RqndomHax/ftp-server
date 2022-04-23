/*
** EPITECH PROJECT, 2022
** my_ftp
** File description:
** ftp_manager
*/

#ifndef FTP_MANAGER_H_
    #define FTP_MANAGER_H_
    #include "my_ftp.h"

void destroy_ftp(my_ftp_t *ftp);

int initialize_server(my_ftp_t *ftp);

void run_ftp(my_ftp_t *ftp);

#endif /* !FTP_MANAGER_H_ */
