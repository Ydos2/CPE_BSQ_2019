/*
** EPITECH PROJECT, 2019
** bsq_dlc3
** File description:
** bsq_dlc3
*/

#include "include/my.h"

int first_line(int fd, int *first, char *tmp, t_max *max)
{
    int	i = 0;
    int	size_max = max->size;

    while (read(fd, &tmp[i], 1) > 0 && tmp[i] != '\n') {
        first[i] = 0;
        if (tmp[i] == '.') {
            first[i] = 1;
            if (size_max <= 0)
                size_max = save_max(max, i, 1, 1);
        }
        else if (tmp[i] != 'o')
            return (84);
        i++;
    }
    if (tmp[i] == 0)
        return (84);
    return (0);
}

int first_car(char *tmp, int *ptr2, t_max *max, int line)
{
    ptr2[0] = 0;
    if (tmp[0] == '.')
        ptr2[0] = 1;
    else if (tmp[0] != 'o' && tmp[0] != '\n')
        return (84);
    if (max->size <= 0 && ptr2[0] == 1)
        max->size = save_max(max, 0, line, ptr2[0]);
    return (0);
}

void swap_ptr(unsigned int **ptr1, unsigned int **ptr2)
{
    unsigned int *swap;

    swap = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = swap;
}

int save_max(t_max *max, int i, int line, int current)
{
    max->size = current;
    max->x_max = i + 1;
    max->y_max = line;
    return (current);
}