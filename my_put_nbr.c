/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** write number
*/
#include <stdio.h>

void my_putchar(char c);

static void positive(int nb)
{
    int quot = 1000000000;
    int digit = 0;

    while (digit == 0) {
        digit = (nb / quot) % 10;
        quot = quot / 10;
    }
    my_putchar(digit + 48);
    quot = quot * 10;
    while (quot != 1) {
        quot = quot / 10;
        digit = (nb / quot) % 10;
        my_putchar(digit + 48);
    }
}

static void negative(int nb)
{
    int quot = 1000000000;
    int digit = 0;

    nb = nb * (-1);
    my_putchar('-');
    if (0 <= nb && nb < 10) {
        my_putchar(nb + 48);
    } else {
        while (digit == 0) {
            digit = (nb / quot) % 10;
            quot = quot / 10;
        }
        my_putchar(digit + 48);
        quot = quot * 10;
        while (quot != 1) {
            quot = quot / 10;
            digit = (nb / quot) % 10;
            my_putchar(digit + 48);
        }
    }
}

void my_put_nbr(int nb)
{
    if (nb < 0) {
        negative(nb);
    } else {
        if (0 <= nb && nb < 10) {
            my_putchar(nb + 48);
        } else {
            positive(nb);
        }
    }
}
