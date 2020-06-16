#include "sort.h"
/**
*bubble_sort - sort bubble
*@array: array of numbers to sort
*@size: size of array
*/
void bubble_sort(int *array, size_t size)
{
	unsigned int swaps = 1, i;
	int tmp;

	if (array == NULL && size > 0)
		while (swaps != 0)
		{
			swaps = 0;
			for (i = 0; i < (size - 1); i++)
			{
				if (array[i] > array[i + 1])
				{
					tmp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = tmp;
					swaps = 1;
					print_array(array, size);
				}
			}
		}
}