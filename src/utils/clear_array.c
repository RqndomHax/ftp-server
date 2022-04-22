/*
** EPITECH PROJECT, 2022
** utils
** File description:
** clear_array
*/

#include <stdlib.h>

void clear_array(char **array)
{
    if (!array)
        return;
    for (int i = 0; array[i]; free(array[i++]));
    free(array);
}