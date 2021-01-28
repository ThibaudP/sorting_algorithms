#include "sort.h"

/**
 * selection_sort - sorts an array of integers using selection sort
 *
 * @array: the array of integers
 * @size: the size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int tmp;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

		if (min != i)
		{
			tmp = array[min];
			array[min] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
