/*
** EPITECH PROJECT, 2022
** my_ftp
** File description:
** clear_string_end
*/

void clear_string_end(char *string, int length)
{
    for (int i = 1; i <= 2 && i <= length; i++)
        if (string[length - i] == '\n' || string[length - i] == '\r')
            string[length - i] = 0;
}
