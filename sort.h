#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */

typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
int partition(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort_helper(int *array, int low, int high, size_t size);
void insertion_sort_list(listint_t **list);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge(size_t low, size_t mi, size_t high, int *dest, int *src);
void merge_sort(int *array, size_t size);
void merge_partition(size_t low, size_t high, int *array, int *base);
void swap_root(int *array, size_t root, size_t high, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);


#endif
