#include "push_swap.h"
#include <stdio.h>

int check_error(int argc) {
    if (argc < 3)
        return (1);
    return (0);
}

void sort_two(char **argv){
    int first;
    int second;
    int flag;

    first = ft_atoi_with_error(argv[1], &flag);
    second = ft_atoi_with_error(argv[2], &flag);
    if(flag)
        return;
    if (first > second)
        write(1, "sa\n", 3);
    return;
}

int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;

    if (check_error(argc))
        return (error_exit(NULL, NULL), 1);
    if (init_stack(&a, argc, argv) == 0)
        return (error_exit(NULL, NULL), 1);
    if (has_duplicates(&a))
        return (error_exit(&a, NULL), 1);
    if (argc == 3)
        return (sort_two(argv), 0);
    b.data = (int *)malloc(sizeof(int) * (argc - 1));
    if (!b.data)
        return (error_exit(&a, NULL), 1);
    b.size = 0;
    if (a.size == 3)
        sort_three(&a);
    else if (is_sorted(&a) == 0)
        radix_sort(&a, &b);
    int k = 0;
    while(k < a.size)
    {
        printf("%d ", a.data[k]);
        k++;
    }
    free_stack(&a);
    free_stack(&b);
    return (0);
}
