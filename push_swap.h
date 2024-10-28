#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
    int *data;
    int size;
}   t_stack;

void    error_exit(t_stack *a, t_stack *b);
int     is_sorted(t_stack *a);
int    init_stack(t_stack *a, int argc, char **argv);
void radix_sort(t_stack *a, t_stack *b);
void    sa(t_stack *a);
void    pb(t_stack *a, t_stack *b);
void    pa(t_stack *a, t_stack *b);
void    ra(t_stack *a);
void    rra(t_stack *a);
void    sort_three(t_stack *a);
void    push_swap(t_stack *a, t_stack *b);
void    free_stack(t_stack *stack);
int     has_duplicates(t_stack *a);
int ft_atoi_with_error(const char *str, int *error_flag);
int compare(const void *a, const void *b);
int check_error(int argc);
void swap(int *a, int *b);
int partition(int *arr, int low, int high, int (*cmp)(const void *, const void *));
void quick_sort(int *arr, int low, int high, int (*cmp)(const void *, const void *));

#endif
