/*
** EPITECH PROJECT, 2022
** my_ftp
** File description:
** ftp_command
*/

#ifndef FTP_COMMAND_H_
    #define FTP_COMMAND_H_
    #include "client_list.h"

typedef struct my_ftp_s my_ftp_t;

typedef struct command_s {
    char *command_name;
    void (*ptr)(char **args, my_ftp_t *ftp, client_list_t *client);
}command_t;

#endif /* !FTP_COMMAND_H_ */
