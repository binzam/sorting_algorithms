#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge_sort - sorts an array using merge algorithm.
 * @array: array to sort.
 * @size: size of the array.
 * Return: Nothing.
 */
void merge_sort(int *array, size_t size)
{
	size_t i = 0;
	int *base = NULL;

	if (array == NULL || size < 2)
		return;
	base = malloc(sizeof(int) * size);
	if (base == NULL)
		return;
	for (; i < size; i++)
		base[i] = array[i];
	merge_partition(0, size, array, base);
	free(base);
}

/**
 * merge - A function that sorts the subarrays.
 * @low: Lower index.
 * @mid: Middle index.
 * @high: Higher index.
 * @dest: Destination for data.
 * @src: Input data.
 * Return: Nothing
 */
void merge(size_t low, size_t mid, size_t high, int *dest, int *src)
{
	size_t i = 0, j = 0, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(src + low, mid - low);
	printf("[right]: ");
	print_array(src + mid, high - mid);
	i = low;
	j = mid;
	k = low;
	for (; k < high; k++)
	{
		if (i < mid && (j >= high || src[i] <= src[j]))
		{
			dest[k] = src[i];
			i++;
		}
		else
		{
			dest[k] = src[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(dest + low, high - low);
}

/**
 * merge_partition - A funtion that splits the array recursively.
 * @low: Lower index.
 * @high: Higher index.
 * @array: The array to sort.
 * @base: The copy of the array.
 * Return: Nothing.
 */
void merge_partition(size_t low, size_t high, int *array, int *base)
{
	size_t mid = 0;

	if (high - low < 2)
		return;
	mid = (low + high) / 2;
	merge_partition(low, mid, array, base);
	merge_partition(mid, high, array, base);
	merge(low, mid, high, array, base);
	for (mid = low; mid < high; mid++)
		base[mid] = array[mid];
}
