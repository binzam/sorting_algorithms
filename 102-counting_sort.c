#include "sort.h"
/**
 * counting_sort - Sorts integers array in ascending order
 * @array: array to sort
 * @size: size of array
 * Return: nothing
 **/
void counting_sort(int *array, size_t size)
{
    int k, j, *a, *counter;
    size_t i;

    if (array == NULL || size < 2)
        return;
    k = array[0];
    for (i = 0; i < size; i++)
    {
        if (array[i] > k)
            k = array[i];
    }
    counter = calloc((k + 1), sizeof(int));
    for (i = 0; i < size; i++)
    {
        counter[array[i]]++;
    }
    for (j = 1; j < k; j++)
    {
        counter[j + 1] += counter[j];
    }
    print_array(counter, k + 1);
    a = malloc(sizeof(int) * size);
    for (i = 0; i < size; i++)
    {
        counter[array[i]]--;
        a[counter[array[i]]] = array[i];
    }
    for (i = 0; i < size; i++)
    {
        array[i] = a[i];
    }
    free(a);
    free(counter);
}
