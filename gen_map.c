/*
** EPITECH PROJECT, 2019
** bsq_error
** File description:
** gen_map
*/

#include "include/my.h"

static int	get_rand(int y)
{
    int fd;
    int nb;
    float nb2;

    if ((read(fd, &nb, 1)) == 84)
        return (84);
    if ((close(fd)) == 84)
        return (84);
    if (nb < 0)
        nb = -nb;
    nb = nb % 100;
    nb2 = (float)nb / 100;
    return (nb2 * y + 0.5);
}

static int print_it(int x, int y, int density)
{
    int tmp;
    int i = 0;
    int j = 0;

    while (i++ < y) {
        while (j++ < x) {
            if ((tmp = get_rand(y) * 2) < 0)
                return (84);
            else if (tmp < density)
                write(1, "o", 1);
            else
                write(1, ".", 1);
    }
    my_putchar('\n');
    }
    return (0);
}

static int check_bad_car(char *str)
{
    int i = 0;

    while (str[i]) {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (84);
        i++;
    }
    return (0);
}

int gen_map(int argc, char **argv)
{
    int x;
    int y;
    int density;

    if (argc != 5)
        return (84);
    if (check_bad_car(argv[2]) == 84 || check_bad_car(argv[3]) == 84
        || check_bad_car(argv[4]) == 84)
    return (84);
    x = my_atoi(argv[2]);
    y = my_atoi(argv[3]);
    density = my_atoi(argv[4]);
    my_put_nbr(y);
    my_putchar('\n');
    print_it(x, y, density);
    return (84);
}