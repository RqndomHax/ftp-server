/*
** EPITECH PROJECT, 2022
** Bmy_ftp
** File description:
** command_manager
*/

#ifndef COMMAND_MANAGER_H_
    #define COMMAND_MANAGER_H_
    #include <stdio.h>
    #include <string.h>
    #include <command_list.h>

typedef struct my_ftp_s my_ftp_t;

command_list_t *query_command(char const *name, command_list_t *commands);

void command_quit(char **args, my_ftp_t *ftp, client_list_t *client);

void command_pass(char **args, my_ftp_t *ftp, client_list_t *client);

void command_user(char **args, my_ftp_t *ftp, client_list_t *client);

void command_help(char **args, my_ftp_t *ftp, client_list_t *client);

void command_noop(char **args, my_ftp_t *ftp, client_list_t *client);

void command_unimplemented(char **args, my_ftp_t *ftp, client_list_t *client);

void command_directory_get(char **args, my_ftp_t *ftp, client_list_t *client);

void command_directory(char **args, my_ftp_t *ftp, client_list_t *client);

void command_directory_up(char **args, my_ftp_t *ftp, client_list_t *client);

void command_delete(char **args, my_ftp_t *ftp, client_list_t *client);

int has_required_power(client_list_t *client, int required_power);

#endif /* !COMMAND_MANAGER_H_ */
