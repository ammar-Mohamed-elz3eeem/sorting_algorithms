#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - function thay sorts linked list
 * using insertion sort Algorithm
 * @list: list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node = *list;
	listint_t *tmp = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	node = node->next;
	while (node != NULL)
	{
		while (node->prev && (node->prev)->n > node->n)
		{
			tmp = node;
			if (node->next)
				(node->next)->prev = tmp->prev;
			(node->prev)->next = tmp->next;
			node = node->prev;
			tmp->prev = node->prev;
			tmp->next = node;
			if (node->prev)
				(node->prev)->next = tmp;
			node->prev = tmp;
			if (tmp->prev == NULL)
				*list = tmp;
			print_list(*list);
			node = node->prev;
		}
		node = node->next;
	}
}
