#include "sort.h"

/**
 * swap - swaps two integers
 *
 * @a: first integer
 * @b: second integer
 *
 * Return: void
 */

void swap(int *a, int *b)
{
	int temp;

	temp = *b;
	*b = *a;
	*a = temp;
}

/**
 * shell_sort - sorts an array using shell algorithm
 *
 * @array:array to sort
 * @size:size of array
 *
 * Return:void
 */

void shell_sort(int *array, size_t size)
{
	size_t i, j, interval;

	if (array == NULL || size < 2)
		return;

	for (interval = 1; interval < (size / 3);)
		interval = interval * 3 + 1;

	for (; interval >= 1; interval /= 3)
	{
		for (i = interval; i < size; i++)
		{
			j = i;
			while (j >= interval && array[j - interval] > array[j])
			{
				swap(array + j, array + (j - interval));
				j -= interval;
			}
		}
		print_array(array, size);
	}
}
