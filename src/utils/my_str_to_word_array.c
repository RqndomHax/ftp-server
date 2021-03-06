/*
** EPITECH PROJECT, 2022
** utils
** File description:
** my_str_to_word_array
*/

#include <string.h>
#include <stdlib.h>
#include <my_utils.h>

static int compare_str(word_array_t *info, int index)
{
    if (strncmp(&info->str[index], info->dlm, info->dlm_size))
        return (0);
    return (1);
}

static int get_word_array_size(word_array_t *info)
{
    int size = 1;
    int compared = 0;

    for (int i = 0; info->str[i]; i++) {
        compared = compare_str(info, i);
        if (compared) {
            size++;
            i += info->dlm_size - 1;
            compared = 0;
            continue;
        }
    }
    return (size);
}

static int translate_to_word(word_array_t *info, int re, int *index)
{
    int size = 0;
    char **r = info->result;
    char *str = info->str;

    if (str[*index] == 0)
        return (1);
    for (int i = *index; !compare_str(info, i) && str[i]; i++, size++);
    size += info->dlm_size - 1;
    r[re] = malloc(size + 1);
    if (r[re] == NULL)
        return (-1);
    for (int i = 0; i < size; r[re][i] = 0, i++);
    for (int i = 0; i < size; r[re][i] = str[*index], i++, *index += 1);
    *index += 1;
    r[re][size] = '\0';
    return (1);
}

static void initialize_info(word_array_t *info, char *str, char *dlm)
{
    info->str = str;
    info->dlm = dlm;
    info->dlm_size = strlen(dlm);
    info->total_size = get_word_array_size(info);
    info->result = malloc(sizeof(char *) * (info->total_size + 1));
}

char **my_str_to_word_array(char *str, char *dlm)
{
    word_array_t info;
    int index = 0;
    int tmp = 0;

    if (!str || !dlm)
        return (NULL);
    initialize_info(&info, str, dlm);
    if (info.result == NULL)
        return (NULL);
    for (int i = 0; i <= info.total_size; info.result[i++] = NULL);
    for (int i = 0; i < info.total_size; i += tmp) {
        tmp = translate_to_word(&info, i, &index);
        if (tmp == -1)
            return (info.result);
    }
    return (info.result);
}
