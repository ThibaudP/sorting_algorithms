#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_next - swaps node with next node
 *
 * @list: address of pointer to head
 * @node: node to swap
 */

void swap_next(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}


/**
 * cocktail_sort_list - sorts a list with cocktail shaker
 *
 * @list: the doubly linked list to sort
 */

void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *tmp;

	if (!list || !(*list))
		return;
	
	tmp = *list;	

	while (swapped != 0)
	{
		swapped = 0;
		while (tmp->next)
		{
			if (tmp->next->n < tmp->n)
			{
				swap_next(list, tmp);
				swapped = 1;
				print_list(*list);
			}
			else
				tmp = tmp->next;
		}
		if (!swapped)
			break;

		swapped = 0;
		while (tmp->prev)
		{
			if (tmp->prev->n > tmp->n)
			{
				swap_next(list, tmp->prev);
				swapped = 1;
				print_list(*list);
			}
			else
				tmp = tmp->prev;
		}	
	}
}