#include "sort.h"
#include <stdio.h>
/**
 * slidding_node - swapping nodes
 * @node: pointer to the swapping node
 * @list: list of nodes to be sorted
 * Return: swapped node
 **/
listint_t *slidding_node(listint_t *node, listint_t **list)
{
	listint_t *prev_node = node->prev;
	listint_t *temp_node = node;

	prev_node->next = temp_node->next;

	if (temp_node->next)
		temp_node->next->prev = prev_node;

	temp_node->next = prev_node;
	temp_node->prev = prev_node->prev;
	prev_node->prev = temp_node;

	if (temp_node->prev)
		temp_node->prev->next = temp_node;
	else
		*list = temp_node;
	return (temp_node);
}
/**
 *cocktail_sort_list - this is a cocktail sort implementation
 *working on a double linked lists
 *@list: list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	int swap_done = 1;

	if (list == NULL || *list == NULL)
		return;
	node = *list;
	while (swap_done == 1)
	{
		swap_done = 0;
		while (node->next)
		{
			if (node->n > node->next->n)
			{
				node = slidding_node(node->next, list);
				swap_done = 1;
				print_list(*list);
			}
			node = node->next;
		}
		if (swap_done == 0)
			break;
		swap_done = 0;
		while (node->prev)
		{
			if (node->n < node->prev->n)
			{
				node = slidding_node(node, list);
				swap_done = 1;
				print_list(*list);
			}
			else
				node = node->prev;
		}
	}
}
