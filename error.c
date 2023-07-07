/*
** EPITECH PROJECT, 2022
** error.c
** File description:
** scan string and detect if there is an error
*/
#include "include/my.h"

static int scanscaract(char *buff, int i, int sizeline)
{
    int status = 0;

    for (int j = 0; buff[i] != '\0'; i ++) {
        if (buff[i] == '\n')
            status = 1;
        if ((status == 1 && j == sizeline) || buff[i + 1] == '\0') {
            status = 0;
            j = -1;
        }
        if (status == 1)
            return 84;
        j ++;
    }
    return 0;
}

int scan_string(char const *str)
{
    for (int i = 0; str[i] != '\0'; i ++) {
        if (str[i] != 'o' && str[i] != '.')
            return 84;
    }
    return 0;
}

int testab(int countline, int sizeline, char *buff)
{
    int i = 0;

    if (my_getnbr(buff) != countline)
        return 84;
    while (buff[i] != '\n')
        i ++;
    i ++;
    if (scanscaract(buff, i, sizeline) == 84)
        return 84;
    for (; buff[i] != '\0'; i ++) {
        if (buff[i + 1] != '\0')
            return 0;
        if (buff[i] != 'o' && buff[i] != '.' && buff[i] != '\n') {
            return 84;
        }
    }
    return 0;
}
