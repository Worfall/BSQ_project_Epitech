/*
** EPITECH PROJECT, 2022
** linelen.c
** File description:
** count size line
*/

int linelen(char const *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\n')
        i ++;
    i ++;
    while (str[i] != '\n') {
        i ++;
        j ++;
    }
    return j;
}
