#include "sort.h"

/**
 * selection_sort - sort array in ascending order
 * @array: array of ints
 * @size: size of array
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	unsigned int n = 0;

	if (!array || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		n = size - 1;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[n])
				n = j;
		}
		if (array[i] != array[n])
		{
			swap(&array[i], &array[n]);
			print_array(array, size);
		}
	}
}
