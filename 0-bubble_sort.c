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
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 *
 * @array: arrray to be sorted
 * @size: length of the array
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	for (i = 0; i < size - 1 ; i++)
	{
		for (j = 0; j < size - 1 - i ; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
