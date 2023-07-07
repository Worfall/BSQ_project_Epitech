/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** prototypes
*/

#ifndef MY_H_
    #define MY_H_
    #include "stdlib.h"
    struct DATA {
        char c;
        char *str;
        int countline;
        int linelen;
        int len;
        int i;
        int j;
        int k;
        int l;
        int tempsize;
        int x;
        int y;
        int size;
        int sizebuff;
    };
    int backslashnlen(char const *str);
    int linelen(char const *str);
    int my_getnbr(char const *str);
    int my_strlen(char const *str);
    int testab(int countline, int sizeline, char *buff);
    int findsquare(struct DATA *data, char tab[data->countline][data->linelen]);
    void creat_map(struct DATA *data, char tab[data->countline][data->linelen]);
    int p_square(struct DATA *data, char tab[data->countline][data->linelen]);
    void my_put_nbr(int nb);
    int scan_string(char const *str);
#endif /* MY_H_ */
