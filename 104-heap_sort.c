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
 * heapify - finds largest among root, right and left
 *
 * @array: array to sort
 * @n: int
 * @i: int
 * @size: size
 *
 * Return: void
 */

void heapify(int *array, int n, int i, int size)
{
	int largest = i, left, right;

	left = 2 * i + 1;
	right = 2 * i + 2;

	if (left < n && array[left] > array[largest])
		largest = left;

	if (right < n && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, size);
		heapify(array, n, largest, size);
	}
}

/**
 * heap_sort - sorts an array using heap sort algorithm
 *
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */

void heap_sort(int *array, size_t size)
{
	int i, temp;

	size = (int)size;
	temp = size;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, temp);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, temp);
		heapify(array, i, 0, temp);
	}
}
