#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: The list to be printed
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *sort;
	listint_t *curr_node = (*list)->next;
	listint_t *next;

	while (curr_node != NULL)
	{
		next = curr_node->next;
		if (curr_node != NULL && curr_node->n < curr_node->prev->n)
		{
			sort = curr_node;
			while (sort->prev != NULL && sort->n <= sort->prev->n)
			{
				swap_prev(sort, list);
				print_list(*list);
			}
		}
		curr_node = next;
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
