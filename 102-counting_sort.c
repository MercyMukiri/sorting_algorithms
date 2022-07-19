#include "sort.h"

/**
 * counting_sort - sorts an array using counting sort algorithm
 *
 * @array:array to sort
 * @size:size of array
 *
 * Return: void
 */

void counting_sort(int *array, size_t size)
{
	int *output, *count, i, max;

	if (array == NULL || size < 2)
		return;
	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;
	max = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count = malloc(sizeof(int) * max + 1);
	if (count == NULL)
		return;
	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
	{
		count[array[i]]++;
	}
	for (i = 0; i <= max; i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);
	for (i = size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
