#include "sort.h"
/**
 * cocktail_sort_list - sorting the list with cock tail algorithm
 * @list: list to be sorted
 **/
void cocktail_sort_list(listint_t **list)
{
	listint_t *temp_node;
	int status = 1;

	void cocktail_checking_null(listint_t **list);
	temp_node = *list;
	while (status == 1)
	{
		status = 0;
		while (temp_node->next != NULL)
		{
			if (temp_node->n > temp_node->next->n)
			{
				temp_node = slidding_node(temp_node->next, list);
				status = 1;
				print_list(*list);
			}
			temp_node = temp_node->next;
		}
		check_if_swapped(status);
		status = 0;
		while (temp_node->prev)
		{
			if (temp_node->n < temp_node->prev->n)
			{
				temp_node = slidding_node(temp_node, list);
				status = 1;
				print_list(*list);
			}
			else
				temp_node = temp_node->prev;
		}
	}
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
