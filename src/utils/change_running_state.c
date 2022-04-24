/*
** EPITECH PROJECT, 2022
** my_utils
** File description:
** change_running_state
*/

#include <my_ftp.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

void change_running_state(my_ftp_t *ftp)
{
    static my_ftp_t *instance = NULL;

    if (instance == NULL) {
        printf("instance is null, new pointer = %p\n", ftp);
        instance = ftp;
        return;
    }
    printf("call on running state, %p\n", instance);
    if (instance != NULL)
        instance->is_running = 0;
}

void signal_handler(int sing_num)
{
    printf("Here!\n");
    fflush(stdout);
    signal(SIGINT, signal_handler);
    change_running_state(NULL);
}
