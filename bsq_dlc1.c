/*
** EPITECH PROJECT, 2019
** bsq_dlc1
** File description:
** bsq_dlc1
*/

#include "include/my.h"

int	get_nb_lines(int *fd, char *file)
{
    int i = 0;
    char nb_lines[15];

    *fd = open(file, O_RDONLY);
    while (read(*fd, &nb_lines[i], 1) > 0 && nb_lines[i] != '\n' && i < 15)
        i++;
    nb_lines[i] = 0;
    return (my_atoi(nb_lines));
}

int get_nb_cols(char *file)
{
    int fd = open(file, O_RDONLY);
    char tmp;
    int i = 0;

    while (read(fd, &tmp, 1) > 0 && tmp != '\n');
    while (read(fd, &tmp, 1) > 0 && tmp != '\n')
        i++;
    close(fd);
    return (i);
}

int go_first_line(char *file, int *fd)
{
    char tmp = 0;
    int i = 0;

    *fd = open(file, O_RDONLY);
    while (read(*fd, &tmp, 1) > 0 && tmp != '\n');
    tmp = 0;
    while (read(*fd, &tmp, 1) > 0 && tmp != '\n')
        i++;
    close(*fd);
    *fd = open(file, O_RDONLY);
    tmp = 0;
    while (read(*fd, &tmp, 1) > 0 && tmp != '\n');
    return (i);
}