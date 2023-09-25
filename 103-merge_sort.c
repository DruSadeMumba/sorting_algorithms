#include "sort.h"
/**
 * join_split_array - joing the splitted array
 * @split_array: splitted array
 * @temp: new array
 * @head: element at lower boundary
 * @end: element at the upper boundary
 * @center: mid value
 **/
void join_split_array(int *split_array, int *temp, size_t head, size_t center,
		size_t end)
{
	size_t x, y, z;

	x = 0;
	y = 0;
	y = 0;

	printf("Merging...\n[left]: ");
	print_array(split_array + head, center - head);

	printf("[right]: ");
	print_array(split_array + center, end - center);

	x = head;
	y = center;
	for (z = 0; x < center && y < end; z++)
	{
		if (split_array[x] < split_array[y])
		{
			temp[z] = split_array[x];
			x++;
		}
		else
		{
			temp[z] = split_array[y];
			y++;
		}
	}

	for (; x < center; x++)
		temp[z++] = split_array[x];
	for (; y < end; y++)
		temp[z++] = split_array[y];
	for (x = head, z = 0; x < end; x++)
		split_array[x] = temp[z++];

	printf("[Done]: ");
	print_array(split_array + head, end - head);
}

/**
 * invoke_merge_sort - invoking repeatedly for merge sorting
 * @split_array: splitted array
 * @temp: new array
 * @head: element at lower boundary
 * @end: element at the upper boundary
 **/
void invoke_merge_sort(int *split_array, int *temp, size_t head, size_t end)
{
	size_t center;

	if (end - head > 1)
	{
		center = head + (end - head) / 2;
		invoke_merge_sort(split_array, temp, head, center);
		invoke_merge_sort(split_array, temp, center, end);
		join_split_array(split_array, temp, head, center, end);
	}
}

/**
 * merge_sort - implementation of merging algorithm
 * @array: array to be sorted
 * @size: size of the array
 **/
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;

	invoke_merge_sort(array, temp, 0, size);

	free(temp);
}
