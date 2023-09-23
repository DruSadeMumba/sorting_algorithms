#include "sort.h"

/**
 * swap - swap 2 ints
 * @a: int 1
 * @b: int 2
*/
void swap(int *x, int *y)
{
	int temp = *x;

	*x = *y;
	*y = temp;
}

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
		if (i != n)
		{
			swap(&array[i], &array[n]);
			print_array(array, size);
		}
	}
}
