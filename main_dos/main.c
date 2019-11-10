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

static int put_int_tab(char *tmp, unsigned int *ptr1,
                unsigned int *ptr2, t_max *max)
{
    static int line;
    unsigned int size_max;
    unsigned int i;

    i = 1;
    ((max->new)++ == 1) ? (line = 2) : (0);
    if ((init_first_car(tmp, ptr2, max, line)) != 0)
        return (84);
    size_max = max->size;
    while (tmp[i] != '\n') {
        ptr2[i] = 0;
    if (tmp[i] == '.') {
        ptr2[i] = minimum(ptr2[i - 1], ptr1[i - 1], ptr1[i]) + 1;
        if (ptr2[i] > size_max)
            size_max = save_max(max, i, line, ptr2[i]);
    } else if (tmp[i] != 'o')
        return (84);
    ++i;
    }
    ++line;
    return (0);
}

static int bsq(int fd, int nb_lines, int nb_cols, t_max *max)
{
    char *tmp;
    unsigned int *ptr1;
    unsigned int *ptr2;
    unsigned int i = 0;

    tmp = (char *)malloc(sizeof(char) * (nb_cols + 2));
    ptr1 = (int *)malloc(sizeof(int) * (nb_cols + 1));
    ptr2 = (int *)malloc(sizeof(int) * (nb_cols + 1));
    if (tmp == NULL || ptr1 == NULL || ptr2 == NULL)
        return (84);
    if (init_first_line(fd, ptr1, tmp, max) == 84)
        return (84);
    while (++i < nb_lines) {
        if (read(fd, &tmp[0], nb_cols + 1) != nb_cols + 1)
            return (84);
        if ((put_int_tab(&tmp[0], ptr1, ptr2, max)) == 84)
            return (84);
    swap_ptr(&ptr1, &ptr2);
    }
    if (read(fd, &tmp[0], nb_cols + 1) > 0)
        return (84);
    free_int(&ptr1, &ptr2, &tmp);
    return (0);
}

static int prepare_bsq(char *file, int flag_c)
{
    int nb_lines;
    int nb_cols;
    t_max maximum;
    char tmp;
    int fd;

    maximum.size = 0;
    maximum.new = 1;
    nb_lines = get_nb_lines(&fd, file);
    if (nb_lines == 84)
        return (84);
    nb_cols = get_nb_cols(file);
    if (nb_cols == 84)
        return (84);
    if ((bsq(fd, nb_lines, nb_cols, &maximum)) == 84) {
        close(fd);
        return (84);
    }
    close(fd);
    if (flag_c == 0)
        fd = disp_bsq(file, &maximum, nb_lines, nb_cols);
    return ((fd == 84) ? (84) : (close(fd)));
}

int	main(int argc, char **argv)
{
    int i = 1;
    int file_actual = 1;
    int nb_files;
    int flag_c = 0;

    if (argc == 1)
        return (84);
    flag_c = get_option(argc, argv);
    if (flag_c == 84)
        return (84);
    nb_files = nb_file(argc, argv);
    if (nb_files == 0)
        return (84);
    while (file_actual <= nb_files) {
        if ((prepare_bsq(argv[i++], flag_c)) == 84)
            return (84);
        if (file_actual++ < nb_files)
            my_putstr("\n");
    }
    return (0);
}