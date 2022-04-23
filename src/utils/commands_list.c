/*
** EPITECH PROJECT, 2022
** my_ftp
** File description:
** utils
*/

#include <stdlib.h>
#include <command_list.h>

void destroy_commands(command_list_t **list)
{
    command_list_t *current = *list;
    command_list_t *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *list = NULL;
}

command_list_t *add_to_commands(command_list_t **list, command_t command)
{
    command_list_t *target;
    command_list_t *to_last = *list;

    target = malloc(sizeof(command_list_t));
    if (target == NULL)
        return (NULL);
    target->command = command;
    target->command.command_name = command.command_name;
    target->next = NULL;
    if (*list == NULL) {
        *list = target;
        return (target);
    }
    while (to_last->next != NULL)
        to_last = to_last->next;
    to_last->next = target;
    return (target);
}
