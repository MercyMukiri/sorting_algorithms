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
 * get_pivot - sorts elements less than pivot to the left and elements
 * greater than pivot to the right of pivot using the Quick sort algorithm
 *
 * @array: arrray to be sorted
 * @low: first element of array
 * @high: last element of array
 *
 * Return: index of pivot
 */

int get_pivot(int *array, int low, int high)
{
	int pivot, i, j, temp;
	static int size, k;

	if (k == 0)
	{
		size = high + 1;
		k++;
	}

	pivot = array[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}

	if (i != high)
	{
		temp = array[i];
		array[i] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i);
}

/**
 * quicksort_recursive - recursive quick sort function
 *
 * @array: arrray to be sorted
 * @low: first element of array
 * @high: last element of array
 *
 * Return: void
 */

void quicksort_recursive(int *array, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = get_pivot(array, low, high);
		quicksort_recursive(array, low, pivot - 1);
		quicksort_recursive(array, pivot + 1, high);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: arrray to be sorted
 * @size: size of the array
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL)
		return;

	quicksort_recursive(array, 0, size - 1);
}
