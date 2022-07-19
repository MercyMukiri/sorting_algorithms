#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: doubly linked list
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node;
	listint_t *temp;

	if (list == NULL)
		return;

	node = *list;

	while (node != NULL)
	{
		while (node->next && (node->n > node->next->n))
		{
			temp = node->next;
			node->next = temp->next;
			temp->prev = node->prev;

			if (node->prev != NULL)
				node->prev->next = temp;

			if (temp->next != NULL)
				temp->next->prev = node;

			node->prev = temp;
			temp->next = node;

			if (temp->prev)
				node = temp->prev;
			else
				*list = temp;

			print_list(*list);
		}
		node = node->next;
	}
}
