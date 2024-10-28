#include "push_swap.h"

void sa(t_stack *a)
{
    int temp;
    if (a->size < 1)
        return;
    temp = a->data[0];
    a->data[0] = a->data[1];
    a->data[1] = temp;
    write(1, "sa\n", 3);
}

void pb(t_stack *a, t_stack *b) {
    if (a->size <= 0) 
        return;
    b->data[++(b->size)] = a->data[0];
    for (int i = 0; i < a->size - 1; i++)
        a->data[i] = a->data[i + 1];
    a->size--;
    write(1, "pb\n", 3);
}

void pa(t_stack *a, t_stack *b) {
    if (b->size < 0)
        return;
    for (int i = a->size; i > 0; i--)
        a->data[i] = a->data[i - 1];
    a->data[0] = b->data[b->size--];
    a->size++;
    write(1, "pa\n", 3);
}


void ra(t_stack *a) {
    int temp;
    if (a->size <= 1)
        return;
    temp = a->data[0];
    for (int i = 0; i < a->size - 1; i++)  // Correct upper bound
        a->data[i] = a->data[i + 1];
    a->data[a->size - 1] = temp;
    write(1, "ra\n", 3);
}

void rra(t_stack *a) {
    int temp;
    if (a->size <= 1)
        return;
    temp = a->data[a->size - 1];
    for (int i = a->size - 1; i > 0; i--)  // Correct lower bound
        a->data[i] = a->data[i - 1];
    a->data[0] = temp;
    write(1, "rra\n", 4);
}