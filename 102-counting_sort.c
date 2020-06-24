#include "sort.h"

/**
 * counting_sort - function that sorts an array
 * of integers in ascending order
 * using the Counting sort algorithm
 * @array: array to order
 * @size: len the of array
 * Return: Nothing
 */
void counting_sort(int *array, size_t size)
{
	int aux[size], i = 0, *count = NULL, max = 0;

	max = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	max = max + 1;
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		exit(0);

	for (i = 0; i <= max; ++i)
		count[i] = 0;
	count[max + 1] = '\0';

	for (i = 0; i < (int)size; i++)
		count[array[i]]++;

	for (i = 1; i <= max; i++)
		count[i] = count[i] + count[i - 1];
	print_array(count, max);

	for (i = size - 1; i >= 0; i--)
	{
		aux[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = aux[i];
	free(count);
}
