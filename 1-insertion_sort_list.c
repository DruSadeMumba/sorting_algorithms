#include "sort.h"
/**
 * insertion_sort_list - performing the insertion sort
 * @list: list of nodes to be sorted
 **/
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node;

	if (list == NULL || (*list)->next == NULL)
		return;
	current_node = (*list)->next;
	while (current_node != NULL)
	{
		while ((current_node->prev) && (current_node->prev->n > current_node->n))
		{
			current_node = slidding_node(current_node, list);
			print_list(*list);
		}
		current_node = current_node->next;
	}
}

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
