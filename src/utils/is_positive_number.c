/*
** EPITECH PROJECT, 2022
** my_ftp
** File description:
** my_ftp_utils
*/

#include <stdio.h>

int is_positive_number(char const *target)
{
    for (int i = 0; target[i]; i++)
        if (target[i] < '0' || target[i] > '9')
            return (0);
    return (1);
}
