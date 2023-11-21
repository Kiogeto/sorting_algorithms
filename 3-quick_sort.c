#include "sort.h"

/**
 * swap_int - swaps two elements in an array
 * @a: the first element
 * @b: the second element
 */

void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - partition through an array of integers
 * @array: array of integers
 * @size: the size of the array
 * @l: first index of array
 * @h: last index of array
 *
 * Description: all values must be accurate
 * Return: new index position
 */
int lomuto_partition(int *array, size_t size, int l, int h)
{
	int pivot = array[h], i = l, j;

	for (j = l; j <= h - 1; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap_int(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (pivot != array[i])
	{
		swap_int(&array[i], &array[h]);
		print_array(array, size);
	}
	return (i);
}

/**
 * lomuto_sort - implement the quick sort algorithm using recursion
 * @array: the array
 * @size: the size of the array
 * @l: first index of the array
 * @h: the last index of the array
 * Return: 0
 */

void lomuto_sort(int *array, size_t size, int l, int h)
{
	int i;

	if (l < h)
	{
		i = lomuto_partition(array, size, l, h);
		lomuto_sort(array, size, l, i - 1);
		lomuto_sort(array, size, i + 1, h);
	}
}

/**
 * quick_sort - sort an array of integers in ascending order
 * @array: the array
 * @size: the size of the array
 * Return: 0
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}
