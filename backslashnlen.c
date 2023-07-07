/*
** EPITECH PROJECT, 2022
** backslashnlen
** File description:
** count number line
*/

int backslashnlen(char const *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\n')
        i ++;
    i ++;
    while (str[i] != '\0') {
        if (str[i] == '\n')
            count ++;
        i ++;
    }
    return count;
}
