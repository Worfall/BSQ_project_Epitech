/*
** EPITECH PROJECT, 2022
** bsq.c
** File description:
** find the bigger square in file
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "include/my.h"
#include "unistd.h"

int generator(char **argv, struct DATA *data)
{
    int countline = my_getnbr(argv[1]);
    int sizeline = (my_getnbr(argv[1]));
    char tab[countline][sizeline + 1];

    data->len = my_strlen(argv[2]);
    if (countline < 1 || scan_string(argv[2]) == 84 || data->len < 1)
        return 84;
    data->countline = countline;
    data->linelen = sizeline + 1;
    data->str = argv[2];
    creat_map(data, tab);
    return 0;
}

int getchar(char *buff, struct DATA *data, int i, int j)
{
    char tab[data->countline][data->linelen];
    int k = 0;

    while (buff[i] != '\n')
        i ++;
    i ++;
    if (testab(data->countline, data->linelen, buff) == 84)
        return 84;
    for (; buff[i] != '\0'; i++) {
        if (buff[i] == '\n') {
            tab[j][k] = '\0';
            j ++;
            k = 0;
        } else {
            tab[j][k] = buff[i];
            k ++;
        }
    }
    tab[j][k] = '\0';
    return findsquare(data, tab);
}

int open_file(char const *filepath, struct DATA *data)
{
    struct stat st;
    stat(filepath, &st);
    int fd = open(filepath, O_RDONLY);
    char buff[st.st_size + 1];
    int size;

    data->sizebuff = st.st_size + 1;
    if (fd == -1)
        return 84;
    size = read(fd, buff, st.st_size);
    buff[st.st_size] = '\0';
    close(fd);
    if (size == 1)
        return 84;
    data->linelen = linelen(buff);
    buff[size] = '\0';
    data->countline = backslashnlen(buff);
    data->str = buff;
    data->c = 'n';
    return getchar(buff, data, 0, 0);
}

int main(int argc, char **argv)
{
    struct DATA *data = malloc(sizeof(struct DATA));

    data->countline = 0;

    if (argc == 3) {
        data->c = 'y';
        return generator(argv, data);
    }
    if (argc == 2)
        return open_file(argv[1], data);
    return 84;
}
