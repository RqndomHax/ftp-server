/*
** EPITECH PROJECT, 2022
** my_utils
** File description:
** append_path
*/

#include <string.h>

char *append_path(char *dest, char *src)
{
    if (src[0] != '/' && dest[strlen(dest) - 1] != '/')
        strcat(dest, "/");
    strcat(dest, src);
    return (dest);
}