#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void sort_three(t_stack *a)
{
    if ((a->data[0] > a->data[1]) && (a->data[1] > a->data[2]))
    {
        sa(a); 
        rra(a);
    }
    else if ((a->data[0] > a->data[2]) && (a->data[2] > a->data[1]))
        ra(a);
    else if ((a->data[1] > a->data[0]) && (a->data[0] > a->data[2]))
        rra(a);
    else if ((a->data[1] > a->data[2]) && (a->data[2] > a->data[0]))
    {
        sa(a);
        ra(a);
    }
    else if ((a->data[2] > a->data[0]) && (a->data[0] > a->data[1]))
        sa(a);
}

void radix_sort(t_stack *a, t_stack *b)
{
    int i, j;
    int max_bits = 0;
    int size = a->size;
    int largest = a->data[0];

    for (i = 1; i < size; i++)
    {
        if (a->data[i] > largest)
            largest = a->data[i];
    }
    while ((largest >> max_bits) != 0)
        max_bits++;
    for (i = 0; i < max_bits; i++)
    {
        for (j = 0; j < size; j++)
        {
            if ((a->data[0] >> i) & 1)
                ra(a);
            else
                pb(a, b);
        }
        while (b->size > 0)
            pa(a, b);
    }
}



