#include "sort.h"
/**
 * find_maximum - compute for maximum value.
 * @arr: given array
 * @n: number of items in array.
 * Return: max_value.
 **/
int find_maximum(int *arr, int n)
{
	int x;
	int i;

	x = arr[0];
	for (i = 1; i < n; i++)
	{
		if (arr[i] > x)
			x = arr[i];
	}

	return (x);
}

/**
 * counting_sort - sorting element by counting algorithm
 * @array: array to be sorted.
 * @size: number of items in the array.
 **/
void counting_sort(int *array, size_t size)
{
	int i, *final, *temp_arr, max_value;

	if (!array || size < 2)
		return;
	final = malloc(sizeof(int) * size);

	if (final == NULL)
		return;

	max_value = find_maximum(array, size);

	temp_arr = malloc(sizeof(int) * (max_value + 1));
	if (!temp_arr)
	{
		free(final);
		return;
	}

	for (i = 0; i < (max_value + 1); i++)
		temp_arr[i] = 0;
	for (i = 0; i < (int)size; i++)
		temp_arr[array[i]] += 1;
	for (i = 0; i < (max_value + 1); i++)
		temp_arr[i] += temp_arr[i - 1];

	print_array(temp_arr, max_value + 1);

	for (i = 0; i < (int)size; i++)
	{
		final[temp_arr[array[i]] - 1] = array[i];
		temp_arr[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = final[i];

	free(final);
	free(temp_arr);
}
