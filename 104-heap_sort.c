#include "sort.h"

/**
 * swap - swap 2 ints
 * @x: int 1
 * @y: int 2
 **/
void swap(int *x, int *y)
{
	int temp = *x;

	*x = *y;
	*y = temp;
}
/**
 * optimize_heap - builds a max heap from a given array
 * @data: a pointer to the first
 * @total_length: number of elements in the array
 * @heap_size: heap size
 * @parent_index: the index to the current parent node
 **/

void optimize_heap(int *data, size_t total_length, size_t heap_size,
		size_t parent_index)
{
	size_t first_child;
	size_t second_child;
	size_t greatest;

	first_child = 2 * parent_index + 1;
	second_child = 2 * parent_index + 2;
	greatest = parent_index;

	if (first_child < heap_size && data[first_child] > data[greatest])
		greatest = first_child;
	if (second_child < heap_size && data[second_child] > data[greatest])
		greatest = second_child;

	if (greatest != parent_index)
	{
		swap(data + parent_index, data + greatest);
		print_array(data, total_length);
		optimize_heap(data, total_length, heap_size, greatest);
	}
}

/**
 * heap_sort - sorting the array using heap sorting algorithm
 * @array: array to be sorted
 * @size: size of the array
 **/
void heap_sort(int *array, size_t size)
{
	int k;

	if (!array || size < 2)
		return;

	k = (size / 2) - 1;
	for (; k >= 0; k--)
		optimize_heap(array, size, size, k);

	k = size - 1;
	while (k > 0)
	{
		swap(array, array + k);
		print_array(array, size);
		optimize_heap(array, size, k, 0);
		k--;
	}
}
