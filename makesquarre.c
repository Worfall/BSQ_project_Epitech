/*
** EPITECH PROJECT, 2022
** makesquarre.c
** File description:
** functions which make squarre
*/
#include "include/my.h"
#include <stdio.h>
#include <unistd.h>

int scan_filledmap(struct DATA *data, char tab[data->countline][data->linelen]);

int findbigsquare(struct DATA *data, char tab[data->countline][data->linelen])
{
    int l = 0;

    if (data->i + data->k == data->countline)
        return 84;
    if (tab[data->i][data->j + data->k] != '.')
        return 84;
    if (tab[data->i + data->k][data->j] != '.')
        return 84;
    if (tab[data->i + data->k][data->j + data->k] != '.')
        return 84;
    l = 0;
    for (; l != data->k; l ++) {
        if (tab[data->i + data->k][data->j + l] != '.')
            return 84;
        if (tab[data->i + l][data->j + data->k] != '.')
            return 84;
    }
    return 0;
}

int scansquare(struct DATA *data, char tab[data->countline][data->linelen])
{
    int stop = 0;

    stop = 0;
    data->k = 0;
    data->tempsize = 0;
    while (stop != 84) {
        if (data->tempsize > data->size) {
            data->size = data->tempsize;
            data->x = data->j;
            data->y = data->i;
        }
        data->tempsize ++;
        while (data->k != data->tempsize && stop != 84) {
            stop = findbigsquare(data, tab);
            data->k = data->k + 1;
        }
        data->k = 0;
    }
    return 0;
}

int putsquare(struct DATA *data, char tab[data->countline][data->linelen])
{
    int j = 0;

    if (data->size > data->linelen)
        data->size = data->linelen;
    tab[data->y][data->x] = 'x';
    for (int i = 0; i != data->size || j != data->size - 1; i++) {
        if (i == data->size) {
            i = -1;
            j ++;
        } else
            tab[data->y + j][data->x + i] = 'x';
    }
    p_square(data, tab);
    return 0;
}

int findsquare(struct DATA *data, char tab[data->countline][data->linelen])
{
    data->j = 0;
    data->size = 0;
    data->i = 0;
    if (scan_filledmap(data, tab) == 0)
        return 0;
    for (; data->i != data->countline; data->j ++) {
        if (tab[data->i][data->j] == '.')
            scansquare(data, tab);
        if (tab[data->i][data->j] == '\0') {
            data->j = 0;
            data->i ++;
        }
    }
    putsquare(data, tab);
    return 0;
}
