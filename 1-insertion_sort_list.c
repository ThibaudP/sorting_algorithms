#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - sorts a linked list using insertion sort
 *
 * @list: the address of a pointer to the head of a list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *n1, *n2;

	if (list == NULL || *list == NULL)
		return;
	
	n1 = (*list)->next;

	while (n1 != NULL)
	{
		n2 = n1->next;
		while (n1->prev != NULL && n1->prev->n > n1->n)
		{
			swap_with_prev(list, n1);
			print_list(*list);
		}
		n1 = n2;
	}	
}

/**
 * swap_with_prev - swaps node with previous node
 *
 * @list: pointer to head of list
 * @node: pointer to node
 */

void swap_with_prev(listint_t **list, listint_t *node)
{
	node->prev->next = node->next;

	if (node->next)
		node->next->prev = node->prev;
	
	node->next = node->prev;
	node->prev = node->next->prev;
	node->next->prev = node;
	
	if (!node->prev)
		*list = node;
	else
		node->prev->next = node;
}
