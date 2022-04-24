/*
** EPITECH PROJECT, 2022
** my_ftp
** File description:
** utils
*/

#ifndef UTILS_H_
    #define UTILS_H_
    #include <my_ftp.h>

typedef struct word_array_s
{
    char *str;
    char **result;
    char *dlm;
    int dlm_size;
}word_array_t;

void clear_array(char **array);

char **my_str_to_word_array(char *str, char *dlm);

int is_positive_number(char const *target);

void print_error(char const *message);

int retrieve_client_socket(my_ftp_t *ftp);

void retrieve_commands(command_list_t **commands);

void clear_string_end(char *string, int length);

void change_running_state(my_ftp_t *ftp);

void signal_handler(int sing_num);

#endif /* !UTILS_H_ */
