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
 * bitonic_merge - merge 2 sequences
 * @array: array
 * @size: array size
 * @low: start
 * @cnt: count
 * @dir: direction
*/
void bitonic_merge(int *array, size_t size, int low, int cnt, int dir)
{
	int i = low, k;

	if (cnt > 1)
	{
		k = cnt / 2;
		for (; i < low + k; i++)
			if ((array[i] > array[i + k] && dir == 1) ||
			(array[i] < array[i + k] && dir == 0))
				swap(&array[i], &array[i + k]);
		bitonic_merge(array, size, low, k, dir);
		bitonic_merge(array, size, low + k, k, dir);
	}
}

/**
 * bitonic_sort_recursive - sort recursively
 * @array: array
 * @size: array size
 * @low: start
 * @cnt: count
 * @dir: direction
*/
void bitonic_sort_recursive(int *array, size_t size, int low, int cnt, int dir)
{
	int k;
	char *direc = (dir == 1) ? "UP" : "DOWN";

	if (cnt > 1)
	{
		k = cnt / 2;
		printf("Merging [%d/%lu] (%s):\n", cnt, size, direc);
		print_array(array + low, cnt);

		bitonic_sort_recursive(array, size, low, k, 1);
		bitonic_sort_recursive(array, size, low + k, k, 0);
		bitonic_merge(array, size, low, cnt, dir);

		printf("Result [%d/%lu] (%s):\n", cnt, size, direc);
		print_array(array + low, cnt);
	}
}

/**
 * bitonic_sort - sort an array of ints in ascending order
 * @array: array
 * @size: array size
*/
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	bitonic_sort_recursive(array, size, 0, size, 1);
}
