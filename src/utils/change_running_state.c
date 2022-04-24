/*
** EPITECH PROJECT, 2022
** my_utils
** File description:
** change_running_state
*/

#include <my_ftp.h>
#include <stdlib.h>
#include <ftp_manager.h>
#include <signal.h>
#include <stdio.h>

void change_running_state(my_ftp_t *ftp)
{
    static my_ftp_t *instance = NULL;

    if (instance == NULL) {
        instance = ftp;
        return;
    }
    if (instance != NULL) {
        destroy_ftp(instance);
        instance->is_running = 0;
    }
}

void signal_handler(int sig_num)
{
    (void) sig_num;
    signal(SIGINT, signal_handler);
    change_running_state(NULL);
}
