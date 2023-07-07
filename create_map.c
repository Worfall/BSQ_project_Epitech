/*
** EPITECH PROJECT, 2023
** create_map.c
** File description:
** create map
*/
#include "include/my.h"

static int test_line(int line, int line_max)
{
    while (line > 0) {
        line = line - line_max;
        if (line == 0) {
            return 0;
        }
    }
    return 84;
}

char **c_two_map(struct DATA *data, char tab[data->countline][data->linelen])
{
    int count = 0;

    for (; data->j != data->linelen - 1; data->j ++) {
        if (data->str[data->l])
            tab[data->i][data->j] = data->str[data->l];
        data->l ++;
        count ++;
        if (data->l == data->len)
            data->l = 0;
    }
    tab[data->i][data->j] = '\0';
    return tab;
}

void creat_map(struct DATA *data, char tab[data->countline][data->linelen])
{
    data->i = 0;
    data->j = 0;
    data->l = 0;
    for (int i = 0; i != data->countline; i ++) {
        data->i = i;
        tab = c_two_map(data, tab);
        data->j = 0;
    }
    data->i = 0;
    data->j = 0;
    findsquare(data, tab);
}
