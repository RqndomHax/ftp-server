/*
** EPITECH PROJECT, 2022
** my_ftp
** File description:
** utils
*/

#ifndef UTILS_H_
    #define UTILS_H_

typedef struct word_array_s
{
    char *str;
    char **result;
    char *dlm;
    int dlm_size;
}word_array_t;

typedef struct list_s
{
    int client_socket;
    struct list_s *next;
}list_t;

void list_destroy(list_t **list);

list_t *list_add(list_t **list, int client_socket);

int list_size(list_t *list);

void clear_array(char **array);

char **my_str_to_word_array(char *str, char *dlm);

int is_positive_number(char const *target);

void print_error(char const *message);

#endif /* !UTILS_H_ */
