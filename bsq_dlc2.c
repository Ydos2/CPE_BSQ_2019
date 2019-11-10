/*
** EPITECH PROJECT, 2019
** bsq_dlc2
** File description:
** disp_bsq
*/

#include "include/my.h"

static void	print_line(char *tmp, t_max *max, int nb_cols)
{
    int i = 1;
    write(1, &tmp[0], max->x_max - max->size);
    while (i++ <= max->size)
        write(1, "x", 1);
    i = max->x_max;
    write(1, &tmp[i], nb_cols - i);
}

int	disp_bsq(char *file, t_max *max, int nb_lines, int nb_cols)
{
    char *tmp;
    int fd, i = 1;

    nb_cols = go_first_line(file, &fd);
    if (nb_cols == 84)
        return (84);
    tmp = (char *)malloc(sizeof(char) * (nb_cols + 1));
    if (tmp == NULL)
        return (84);
    tmp[nb_cols++] = 0;
    while (i <= nb_lines) {
        if ((read(fd, tmp, nb_cols)) < 0)
            return (84);
        if (i++ <= max->y_max - max->size || i - 1 > max->y_max)
            write(1, tmp, nb_cols);
        else
            print_line(tmp, max, nb_cols);
    }
    free(tmp);
    return (fd);
}

void free_int(unsigned int **ptr1, unsigned int **ptr2, char **tmp)
{
    if (*ptr1)
        free(*ptr1);
    if (*ptr2)
        free(*ptr2);
    if (*tmp)
        free(*tmp);
}