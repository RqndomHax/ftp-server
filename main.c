/*
** EPITECH PROJECT, 2022
** my_ftp
** File description:
** main
*/

#include <my_ftp.h>
#include <string.h>
#include <args_manager.h>
#include <ftp_manager.h>

static int print_usage(void)
{
    printf("USAGE: ./myftp port path\n");
    printf("\tport is the port number on which the server socket listens\n");
    printf("\tpath is the path to the home directory for the");
    printf(" Anonymous user\n");
    return (0);
}

int main(int argc, char **argv)
{
    int exit_status;
    my_ftp_t *ftp = NULL;

    if (argc == 2 && strcmp(argv[1], "-help") == 0)
        return (print_usage());
    ftp = initialize_ftp(argc, argv);
    if (ftp == NULL)
        return (84);
    exit_status = initialize_server(ftp);
    if (exit_status)
        run_ftp(ftp);
    if (ftp != NULL) {
        destroy_ftp(ftp);
        free(ftp);
    }
    if (!exit_status)
        return (84);
    return (0);
}
