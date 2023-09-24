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
 * shell_sort - sort array of ints in ascending order
 * @array: array to sort
 * @size: array size
*/

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j, n;

	if (!array || size < 2)
		return;
	
	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			n = j - gap;
			while (j >= gap && array[n] > array[j])
			{
				swap(array + j, array + n);
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
