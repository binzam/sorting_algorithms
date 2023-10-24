#include "sort.h"

/**
 * swap_root - swaps the root nodes.
 * @array: The heap to sort.
 * @root: The root of the heap.
 * @high: The higher index.
 * @size: size of the array.
 *
 * Return: Nothing
 */
void swap_root(int *array, size_t root, size_t high, size_t size)
{
	size_t low = 0, mid = 0, tmp = 0;
	int aux = 0;

	while ((low = (2 * root + 1)) <= high)
	{
		tmp = root;
		mid = low + 1;
		if (array[tmp] < array[low])
			tmp = low;
		if (mid <= high && array[tmp] < array[mid])
			tmp = mid;
		if (tmp == root)
			return;
		aux = array[root];
		array[root] = array[tmp];
		array[tmp] = aux;
		print_array(array, size);
		root = tmp;
	}
}

/**
 * heap_sort - sorts an array using heap algorithm.
 * @array: array to sort.
 * @size: size of the array.
 *
 * Return: Nothing.
 */
void heap_sort(int *array, size_t size)
{
	size_t high = 0, gap = 0;
	int tmp = 0;

	if (array == NULL || size < 2)
		return;

	for (gap = (size - 2) / 2; 1; gap--)
	{
		swap_root(array, gap, size - 1, size);
		if (gap == 0)
			break;
	}

	high = size - 1;
	while (high > 0)
	{
		tmp = array[high];
		array[high] = array[0];
		array[0] = tmp;
		print_array(array, size);
		high--;
		swap_root(array, 0, high, size);
	}
}
