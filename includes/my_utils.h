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

void clear_array(char **array);

char **my_str_to_word_array(char *str, char *dlm);

int is_positive_number(char const *target);

#endif /* !UTILS_H_ */
