/*
** EPITECH PROJECT, 2022
** my_ftp
** File description:
** retrieve_workdir
*/

#include <stdlib.h>
#include <string.h>

static int get_total_length(int current_length, int root_length)
{
    if (current_length > root_length)
        return ((current_length - root_length));
    return (1);
}

static char *get_workdir(char *current, int length)
{
    char *workdir = NULL;

    workdir = malloc(length + 1);
    if (workdir == NULL) {
        free(current);
        return (NULL);
    }
    memset(workdir, 0, length);
    return (workdir);
}

char *retrieve_workdir(char *root, char *current)
{
    char *workdir = NULL;
    int length = 0;
    int current_length = 0;
    int root_length = 0;

    if (current == NULL)
        return (NULL);
    current_length = strlen(current);
    root_length = strlen(root);
    length = get_total_length(current_length, root_length) + 1;
    workdir = get_workdir(current, length);
    if (workdir == NULL)
        return (NULL);
    if (current_length > root_length)
        strcat(workdir, &current[root_length - 1]);
    else
        strcat(workdir, "/");
    free(current);
    return (workdir);
}
