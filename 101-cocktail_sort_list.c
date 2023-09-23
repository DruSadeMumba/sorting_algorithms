#include "sort.h"
/**
 * swapping_nodes - swapping two nodes
 * @list: list to be sorted
 * @first_node: first node
 * @second_node: second node
 **/
void swapping_nodes(listint_t **list, listint_t *first_node,
		listint_t *second_node)
{
	if (first_node->prev)
		first_node->prev->next = second_node;
	else
		*list = second_node;

	if (second_node->next)
		second_node->next->prev = first_node;

	first_node->next = second_node->next;
	second_node->next = first_node;

	second_node->prev = first_node->prev;
	first_node->prev = second_node;
}

/**
 * cocktail_sort_list - sorting the list with cock tail algorithm
 * @list: list to be sorted
 **/
void cocktail_sort_list(listint_t **list)
{
	int status;
	listint_t *node_start, *node_end, *temp_node;

	void cocktail_checking_null(listint_t **list);
	do {
		status = 0;
		node_start = *list;
		node_end = NULL;
		temp_node = node_start;

		while (temp_node->next != node_end)
		{
			if (temp_node->n > temp_node->next->n)
			{
				swapping_nodes(list, temp_node, temp_node->next);
				status = 1;
				print_list(*list);
			}
			else
				temp_node = temp_node->next;
		}

		check_if_swapped(status);
		node_end = temp_node;
		temp_node = node_end;

		while (temp_node->prev != node_start)
		{
			if (temp_node->n < temp_node->prev->n)
			{
				swapping_nodes(list, temp_node->prev, temp_node);
				status = 1;
				print_list(*list);
			}
			else
				temp_node = temp_node->prev;
		}
		node_start = temp_node;
	} while (status);
}

/**
 * cocktail_checking_null - checking for the null list
 * @list: list to be sorted
 **/
void cocktail_checking_null(listint_t **list)
{
	if (*list == NULL)
		return;
}
/**
 * check_if_swapped - checking if there was swap
 * @status: flap for checking the status
 **/
void check_if_swapped(int status)
{
	if (!status)
		return;
}
