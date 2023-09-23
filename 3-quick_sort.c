#include "sort.h"

/**
 * swap - swap 2 ints
 * @x: int 1
 * @y: int 2
*/
void swap(int *x, int *y)
{
	int temp = *x;

	*x = *y;
	*y = temp;
}

/**
 * partition - partition array
 * @array: array
 * @size: size
 * @array_b: array
 * @size_b: size
*/
void partition(int *array_b, size_t size_b, int *array, size_t size)
{
	int pivot = size - 1, pos = 0, c = 0;

	if (!array || size < 2)
		return;
	while (array[pos] < array[pivot])
		pos++;
	c = pos;
	for (; pos <= pivot; pos++)
	{
		if (array[pos] <= array[pivot])
		{
			if (array[c] != array[pivot])
			{
				swap(&array[pos], &array[c]);
				print_array(array_b, size_b);
			}
			c++;
		}
	}
	pivot = c - 1;
	partition(array_b, size_b, array, pivot);
	partition(array_b, size_b, array + pivot + 1, size - pivot - 1);
}

/**
 * quick_sort - sort an array in ascending order
 * @array: array to sort
 * @size: array size
*/
void quick_sort(int *array, size_t size)
{
	partition(array, size, array, size);
}
