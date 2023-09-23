#include <stdio.h>
#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 *
 * @list: The list to be printed
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *curr_node;
	int is_swapped = 1;


	while (is_swapped)
	{
		curr_node = (*list)->next;
		is_swapped = 0;
		while (curr_node->next != NULL)
		{
			if (curr_node->n < curr_node->prev->n)
			{
				swap_prev(curr_node, list);
				print_list(*list);
				is_swapped = 1;
			}
			curr_node = curr_node->next;
		}

		if (!is_swapped)
			break;

		is_swapped = 0;
		while (curr_node->prev != NULL)
		{
			if (curr_node->n < curr_node->prev->n)
			{
				swap_prev(curr_node, list);
				print_list(*list);
				is_swapped = 1;
			}
			else
				curr_node = curr_node->prev;
		}
	}

}

/**
 * swap_prev - Swap node with the node of the left.
 *
 * @node: Doubly linked list node
 * @list: Main doubly linked list
*/
void swap_prev(listint_t *node, listint_t **list)
{
	listint_t *prev_node;
	listint_t *prev_prev_node;
	listint_t *next_node;

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
