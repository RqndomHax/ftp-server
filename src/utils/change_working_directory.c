/*
** EPITECH PROJECT, 2022
** my_utils
** File description:
** change_working_directory
*/

#include <unistd.h>
#include <sys/stat.h>

static int has_access(char *path)
{
    struct stat buffer;

    if (access(path, F_OK) || stat(path, &buffer))
        return (0);
    if (!S_ISDIR(buffer.st_mode))
        return (0);
    if (access(path, R_OK))
        return (0);
    return (1);
}

int change_workdir(char *path)
{
    if (!has_access(path))
        return (0);
    chdir(path);
    return (1);
}