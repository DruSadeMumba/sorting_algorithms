#include "deck.h"

/**
 * value_rank - order of card value
 * @value: card value
 * Return: -1
*/
int value_rank(const char *value)
{
	const char *values[] = {
		"Ace", "2", "3", "4", "5", "6", "7",
		"8", "9", "10", "Jack", "Queen", "King"
		};
	int i;

	for (i = 0; i < 13; i++)
	{
		if (strcmp(value, values[i]) == 0)
			return (i);
	}
	return (-1);
}

/**
 * card_compare - compare value and kind of cards
 * @a: void
 * @b: void
 * Return: 0
*/
int card_compare(const void *a, const void *b)
{
	const card_t *cardA = (*(const deck_node_t **)a)->card;
	const card_t *cardB = (*(const deck_node_t **)b)->card;
	int rankA = value_rank(cardA->value);
	int rankB = value_rank(cardB->value);

	if (cardA->kind < cardB->kind)
		return (-1);
	if (cardA->kind > cardB->kind)
		return (1);

	if (rankA < rankB)
		return (-1);
	else if (rankA > rankB)
		return (1);
	
	return (0);
}

/**
 * sort_deck - sort a deck of cards
 * @deck: deck
*/
void sort_deck(deck_node_t **deck)
{
	int count = 0, i;
	deck_node_t *current = *deck, **deck_array;

	while (current)
	{
		count++;
		current = current->next;
	}

	deck_array = malloc(count * sizeof(deck_node_t *));
	if (!deck_array)
	{
		fprintf(stderr, "Malloc fail.\n");
		exit(EXIT_FAILURE);
	}

	current = *deck;
	for (i = 0; i < count; i++)
	{
		deck_array[i] = current;
		current = current->next;
	}

	qsort(deck_array, count, sizeof(deck_node_t *), card_compare);
	*deck = deck_array[0];
	for  (i = 0; i < count - 1; i++)
	{
		deck_array[i]->next = deck_array[i + 1];
		deck_array[i + 1]->prev = deck_array[i];
	}
	deck_array[count - 1]->next = NULL;
	free(deck_array);
}

/**
 * print_sorted_deck - print sorted deck
 * @deck: deck
*/
void print_sorted_deck(deck_node_t *deck)
{
	while (deck)
	{
		printf("%s of %s\n", deck->card->value, deck->card->kind == SPADE ? "S" :
			deck->card->kind == HEART ? "H" :
			deck->card->kind == CLUB ? "C" : "D");
		deck = deck->next;
	}
}
