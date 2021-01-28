#include "sort.h"

/**
 * bubble_sort - sorts an array of integers using bubble sort
 *
 * @array: the array of integers
 * @size: the size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t n = size, new_n, i;
	int tmp = 0;

	while (n > 1)
	{
		new_n = 0;
		for (i = 1; i <= n - 1; i++)
		{
			if (array[i - 1] > array[i])
			{
				tmp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = tmp;
				print_array(array, size);
				new_n = i;
			}
		}
		n = new_n;
	}
}
