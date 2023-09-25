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
 * hoare_partition - hoare partition
 * @array: array
 * @size: size
 * @low: first index
 * @high: last index
*/
int hoare_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low - 1, j = high + 1;

	for (; i < j;)
	{
		do
			i++;
		while (array[i] < pivot);
		do
			j--;
		while (array[j] > pivot);

		if (i < j)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	return (i);
}

/**
 * sort_hoare - sort using recursion
 * @array: array
 * @size: size of array
*/
void sort_hoare(int *array, size_t size, int low, int high)
{
	int part_idx;
	
	if (low < high)
	{
		part_idx = hoare_partition(array, size, low, high);
		sort_hoare(array, size, low, part_idx - 1);
		sort_hoare(array, size, part_idx, high);
	}
}

/**
 * quick_sort_hoare - sorts an array of ints in ascending order
 * @array: array to sort
 * @size: size of array
*/
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	sort_hoare(array, size, 0, size - 1);
}
