#include "push_swap.h"
#include <stdio.h>

int has_duplicates(t_stack *a)
{
    int i;
    int j;

    i = 0;
    while (i < a->size - 1)
    {
        j = i + 1;
        while (j < a->size)
        {
            if (a->data[i] == a->data[j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int is_sorted(t_stack *a)
{
    int i;

    i = 0;
    while (i < a->size - 1)
    {
        if (a->data[i] > a->data[i + 1])
            return (0);
        i++;
    }
    return (1);
}

void free_stack(t_stack *stack)
{
    if (stack && stack->data)
        free(stack->data);
}

int ft_atoi_with_error(const char *str, int *error_flag)
{
    long result;
    int sign;

    sign = 1;
    result = 0;
    *error_flag = 0;
    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    if (!(*str <= '9' && '0' <= *str))
        return(*error_flag = 1, 0);
    while (*str)
    {
        if (*str < '0' || *str > '9')
            return(*error_flag = 1, 0);
        result = result * 10 + (*str - '0');
        if ((sign == 1 && result > INT_MAX) || (sign == -1 && -result < INT_MIN))
            return(*error_flag = 1, 0);
        str++;
    }
    return (int)(result * sign);
}

int init_stack(t_stack *a, int argc, char **argv) {
    int i, j, error_flag;
    int *temp_array;

    a->size = argc - 1;
    a->data = (int *)malloc(sizeof(int) * a->size);
    if (!a->data)
        return (0);
    for (i = 0; i < a->size; i++) {
        a->data[i] = ft_atoi_with_error(argv[i + 1], &error_flag);
        if (error_flag == 1)
            return(free(a->data), 0);
    }
    temp_array = (int *)malloc(sizeof(int) * a->size);
    if (!temp_array)
        return(free(a->data), 0);
    for (i = 0; i < a->size; i++) {
        temp_array[i] = a->data[i];
    }
    quick_sort(temp_array, 0, a->size - 1, compare);
    for (i = 0; i < a->size; i++) {
        for (j = 0; j < a->size; j++) {
            if (a->data[i] == temp_array[j]) {
                a->data[i] = j + 1;
                break;
            }
        }
    }
    free(temp_array);
    return (1);
}