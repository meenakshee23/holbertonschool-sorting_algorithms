#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two integers
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
	if (*a != *b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}
}

/**
 * partition - Lomuto partition for quick sort
 * @array: the array to sort
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 *
 * Return: the index of the pivot after partition
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			swap(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
			i++;
		}
	}
	swap(&array[i], &array[high]);
	if (i != high)
		print_array(array, size);
	return (i);
}

/**
 * quick_sort_recursive - helper for recursive quick sort
 * @array: the array to sort
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = partition(array, low, high, size);

		quick_sort_recursive(array, low, pi - 1, size);
		quick_sort_recursive(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm (Lomuto partition scheme)
 * @array: the array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	size_t i;
	int all_equal = 1;

	if (array == NULL || size < 2)
		return;

	for (i = 1; i < size; i++)
	{
		if (array[i] != array[0])
		{
			all_equal = 0;
			break;
		}
	}

	if (all_equal)
	{
		print_array(array, size);
		return;
	}

	quick_sort_recursive(array, 0, size - 1, size);
}
