#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 *					using the Selection sort algorithm
 * @array: the array to sort
 * @size: size of array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	int aux;
	size_t i, j, pos;

	i = 0;
	pos = i;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[pos])
			{
				pos = j;
			}
			j++;
		}
		if (pos != i)
		{
			aux = array[i];
			array[i] = array[pos];
			array[pos] = aux;
			print_array(array, size);
		}
		i++;
		pos = i;
	}
}
