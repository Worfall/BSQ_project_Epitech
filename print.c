/*
** EPITECH PROJECT, 2023
** print.c
** File description:
** print bsq
*/
#include "include/my.h"
#include "unistd.h"

int p_square(struct DATA *data, char tab[data->countline][data->linelen])
{
    for (int i = 0; i != data->countline; i++) {
        if (data->c == 'n') {
            write(1, tab[i], data->linelen);
        } else {
            write(1, tab[i], data->linelen - 1);
        }
        write(1, "\n", 1);
    }
    return 0;
}

int scan_filledmap(struct DATA *data, char tab[data->countline][data->linelen])
{
    for (int i = 0; data->str[i] != '\0'; i ++) {
        if (data->str[i] == '.')
            return 84;
    }
    return p_square(data, tab);
}
