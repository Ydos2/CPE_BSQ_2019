/*
** EPITECH PROJECT, 2019
** my
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
typedef struct s_max
{
    int x_max;
    int y_max;
    int size;
    int new;
}   t_max;
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
int my_put_nbr_pos(int nbr);
int my_put_nbr_neg(int nbr);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strdup(char const *src);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
char **my_str_to_word_array(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_int_to_str(int nb);
int my_atoi(char *str);
int my_intlen(int nb);

static int bsq(int fd, int nb_lines, int nb_cols, t_max *max);
static int bsq_tab(char *tmp, unsigned int *ptr1,
                unsigned int *ptr2, t_max *max);
static inline int minimum(unsigned int a, unsigned int b,
                unsigned int c);
static int before_bsq(char *file, int flag_c);

void free_int(unsigned int **ptr1, unsigned int **ptr2, char **tmp);

static void	print_line(char *tmp, t_max *max, int nb_cols);
int	display_bsq(char *file, t_max *max, int nb_lines, int nb_cols);

static int get_rand(int y);
static int print_it(int x, int y, int density);
static int check_bad_car(char *str);
int gen_map(int argc, char **argv);
int scribe(int density, int y);

int get_nb_lines(int *fd, char *file);
int get_nb_cols(char *file);
int go_first_line(char *file, int *fd);

int first_line(int fd, int *first, char *tmp, t_max *max);
int first_car(char *tmp, int *ptr2, t_max *max, int line);
void swap_ptr(unsigned int **ptr1, unsigned int **ptr2);
int save_max(t_max *max, int i, int line, int current);
#endif /* !MY_H_ */