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
 * hoare_partition - orders a subset of array according
 * to hoare partition scheme
 *
 * @array: array of integers
 * @size: size of the array
 * @left: starting index of subset
 * @right: ending index of subset
 *
 * Return: Final partition index
 */

int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, below, above;

	pivot = array[right];

	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_recursion - implements the quicksort algorithm through recursion
 *
 * @array: array of integers to sort
 * @size: size of array
 * @left: starting index
 * @right: ending index
 *
 * Return: void
 */

void hoare_recursion(int *array, size_t size, int left, int right)
{
	int seg;

	if (right - left > 0)
	{
		seg = hoare_partition(array, size, left, right);
		hoare_recursion(array, size, left, seg - 1);
		hoare_recursion(array, size, seg, right);
	}
}

/**
 * quick_sort_hoare - sorts an array of integers using quicksort algorithm
 *
 * @array: array of integers
 * @size: size of array
 *
 * Return: void
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_recursion(array, size, 0, size - 1);
}
