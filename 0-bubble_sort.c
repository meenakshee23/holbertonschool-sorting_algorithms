#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using Bubble sort algorithm
 * @array: the array to sort
 * @size: number of elements in array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int temp, swapped;

	if (array == NULL || size < 2)
		return;

	print_array(array, size);

	do {
		swapped = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
				swapped = 1;
			}
		}
		size--;
	} while (swapped);
}
