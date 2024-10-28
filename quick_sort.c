#include "push_swap.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high, int (*compare)(const void *, const void *)) {
    int pivot = arr[high]; 
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (compare(&arr[j], &arr[high]) < 0) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int *arr, int low, int high, int (*cmp)(const void *, const void *)) {
    if (low < high) {
        int pivot_index;
        
        pivot_index = partition(arr, low, high, cmp);
        quick_sort(arr, low, pivot_index - 1, cmp);
        quick_sort(arr, pivot_index + 1, high, cmp);
    }
}
