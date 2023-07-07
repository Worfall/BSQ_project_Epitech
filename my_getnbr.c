/*
** EPITECH PROJECT, 2022
** my_getnbr.c
** File description:
** my_getnbr
*/
#include <stdio.h>
#include <stdbool.h>

int operation(char const *str, int i, bool statutC)
{
    if (str[i] < 48 || 57 < str[i]) {
        if (str[i] == '+' || str[i] == '-') {
            statutC = false;
        } else {
            statutC = true;
        }
    }
    return (statutC);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int nb = 0;
    bool statutC = false;
    int statutN = 0;

    while (str[i] != '\0') {
        statutC = operation(str, i, statutC);
        if (str[i] == '-')
            statutN ++;
        if (str[i] > 47 && str[i] < 58 && statutC == false) {
            nb += str[i] - 48;
            nb = nb * 10;
        }
        i ++;
    }
    nb = nb / 10;
    if (statutN % 2 != 0)
        nb = nb * -1;
    return (nb);
}
