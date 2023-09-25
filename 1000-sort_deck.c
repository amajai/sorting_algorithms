#include <stdio.h>
#include "deck.h"

/**
 * sort_deck - Sorts a doubly linked list of cards in ascending
 * order using the Cocktail shaker sort algorithm
 *
 * @deck: The list of cards
*/
void sort_deck(deck_node_t **deck)
{
	deck_node_t *curr_card;
	int is_swapped = 1, swap_cards = 0;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	while (is_swapped)
	{
		curr_card = (*deck)->next;
		is_swapped = 0;
		while (curr_card->next != NULL)
		{
			swap_cards = card_swap_check(curr_card);

			if (swap_cards)
			{
				swap_prev(curr_card, deck);
				is_swapped = 1;
			}
			curr_card = curr_card->next;
		}

		while (curr_card->prev != NULL)
		{
			swap_cards = card_swap_check(curr_card);
			if (swap_cards)
			{
				swap_prev(curr_card, deck);
				is_swapped = 1;
			}
			else
				curr_card = curr_card->prev;
		}
	}

}
/**
 * card_swap_check - check if the current card should swap with the previous
 * card in doubly linked list when the current card values are less than
 * previous card
 *
 * @curr_card: Current card in the doubly linked list to check
 *
 * Return: 0, not to swap
 * 1, to swap
*/
int card_swap_check(deck_node_t *curr_card)
{
	const char *curr_val, *prev_val;
	kind_t cc_kind, pc_kind;
	int swap_cards = 0;

	curr_val = curr_card->card->value;
	cc_kind = curr_card->card->kind;
	prev_val = curr_card->prev->card->value;
	pc_kind = curr_card->prev->card->kind;


	if (compare_card(curr_val, prev_val) < 0)
		swap_cards = 1;
	if (cc_kind < pc_kind)
		swap_cards = 1;
	else if (cc_kind == pc_kind && compare_card(curr_val, prev_val) < 0)
		swap_cards = 1;
	else
		swap_cards = 0;

	return (swap_cards);
}
/**
 * _strcmp - compares two strings
 * @s1: String one
 * @s2: String two
 * Return: 0 when str are same else the difference
 */
int _strcmp(const char *s1, const char *s2)
{
	int i, diff = 0;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			diff = s1[i] - s2[i];
			break;
		}
		i++;
	}

	return (diff);
}

/**
 * compare_card - differences of two cards values
 * @a: First card
 * @b: Second card to get dfference from the first card
 *
 * Return: 0 if both cards are the same.
 * < 0, if first card value is less than second card.
 * > 0, if first card value is greater than second card.
 */
int compare_card(const char *a, const char *b)
{
	int idx1, idx2, i;
	char *deck[] = {
		"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"
	};

	idx1 = -1;
	idx2 = -1;

	for (i = 0; i < 13; i++)
	{
		if (_strcmp(a, deck[i]) == 0)
		{
			idx1 = i;
		}
		if (_strcmp(b, deck[i]) == 0)
		{
			idx2 = i;
		}
	}
	return (idx1 - idx2);
}

/**
 * swap_prev - Swap node with the node of the left.
 *
 * @node: Doubly linked list node
 * @list: Main doubly linked list
*/
void swap_prev(deck_node_t *node, deck_node_t **list)
{
	deck_node_t *prev_node;
	deck_node_t *prev_prev_node;
	deck_node_t *next_node;

	if (node->prev == NULL)
		return;

	prev_node = node->prev;
	prev_prev_node = prev_node->prev;
	next_node = node->next;

	if (prev_prev_node != NULL)
		prev_prev_node->next = node;
	else
		*list = node;

	node->prev = prev_prev_node;
	node->next = prev_node;

	prev_node->prev = node;
	prev_node->next = next_node;

	if (next_node != NULL)
		next_node->prev = prev_node;
}
