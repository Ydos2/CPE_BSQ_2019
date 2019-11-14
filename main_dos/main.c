/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "../include/my.h"

static inline int minimum(unsigned int a, unsigned int b,
    unsigned int c)
{
    if (a <= b && a <= c)
        return (a);
    else if (b <= a && b <= c)
        return (b);
    else
        return (c);
}

static int bsq_tab(char *tmp, unsigned int *ptr1,
    unsigned int *ptr2, t_max *max)
{
    static int line;
    unsigned int size_max, i = 1, z = 0, y = 0;

    ((max->new)++ == 1) ? (line = 2) : (0);
    y = first_car(tmp, ptr2, max, line);
    if (y != 0)
        return (84);
    size_max = max->size;
    while (tmp[i] != '\n') {
        ptr2[i] = 0;
        if (tmp[i] == '.') {
            ptr2[i] = minimum(ptr2[i - 1], ptr1[i - 1], ptr1[i]) + 1;
            z = 1;
        } else if (tmp[i] != 'o')
            return (84);
        if (ptr2[i] > size_max)
            size_max = save_max(max, i, line, ptr2[i]);
        i++;
    }
    line++;
    return (0);
}

static int bsq(int fd, int nb_lines, int nb_cols, t_max *max)
{
    char *tmp = (char *)malloc(sizeof(char) * (nb_cols + 2));
    unsigned int *ptr1 = (int *)malloc(sizeof(int) * (nb_cols + 1));
    unsigned int *ptr2 = (int *)malloc(sizeof(int) * (nb_cols + 1));
    unsigned int i = 1, j;

    j = first_line(fd, ptr1, tmp, max);
    if (j == 84)
        return (84);
    for (int z, y; i < nb_lines; i++) {
        y = read(fd, &tmp[0], nb_cols + 1);
        if (y != nb_cols + 1)
            return (84);
        z = bsq_tab(&tmp[0], ptr1, ptr2, max);
        if (z == 84)
            return (84);
        swap_ptr(&ptr1, &ptr2);
    }
    if (read(fd, &tmp[0], nb_cols + 1) > 0)
        return (84);
    free_int(&ptr1, &ptr2, &tmp);
    return (0);
}

static int before_bsq(char *file, int flag_c)
{
    int nb_lines, nb_cols, fd, bsq_i;
    t_max maximum;
    char tmp;

    maximum.size = 0;
    maximum.new = 1;
    nb_lines = get_nb_lines(&fd, file);
    if (nb_lines == 84)
        return (84);
    nb_cols = get_nb_cols(file);
    if (nb_cols == 84)
        return (84);
    bsq_i = bsq(fd, nb_lines, nb_cols, &maximum);
    if (bsq_i == 84) {
        close(fd);
        return (84);
    }
    close(fd);
    if (flag_c == 0)
        fd = display_bsq(file, &maximum, nb_lines, nb_cols);
    return ((fd == 84) ? (84) : (close(fd)));
}

int	main(int argc, char **argv)
{
    int i = 1;
    int j;
    int flag_c = 0;

    if (argc == 1)
        return (84);
    j = before_bsq(argv[i++], flag_c);
    if (j == 84)
        return (84);
    return (0);
}