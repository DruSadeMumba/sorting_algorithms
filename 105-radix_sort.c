#include "sort.h"

/**
 * get_max - get max val in array
 * @array: array
 * @size: array size
 * Return: max
*/
int get_max(int *array, size_t size)
{
	size_t i = 1;
	int max = array[0];

	for (; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * count_sorting - sorting based on exp
 * @array: array
 * @size: size
 * @exp: digit
*/
void count_sorting(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size), count[10] = {0};
	size_t i;

	if (!output)
		exit(EXIT_FAILURE);
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1; (int)i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output);
}

/**
 * radix_sort - sorts an array of ints in ascending order
 * @array: array
 * @size: array size
*/
void radix_sort(int *array, size_t size)
{
	int exp = 1, max = get_max(array, size);

	if (!array || size < 2)
		return;

	for (; max / exp > 0; exp *= 10)
	{
		count_sorting(array, size, exp);
		print_array(array, size);
	}
}
