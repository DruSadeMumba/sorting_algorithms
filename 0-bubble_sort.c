#include "sort.h"
/**
 * bubble_sort - swapping the number in the list and sort them
 * @array: array to be sorted
 * @size: the size of the array
 **/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swap_value;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_value = array[j];
				array[j] = array[j + 1];
				array[j + 1] = swap_value;
				print_array(array, size);
			}
		}
	}
}
