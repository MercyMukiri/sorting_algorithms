#include "sort.h"

/**
 * swap_node_infront - swaps a node in ahead manner
 *
 * @list: pointer to head of a doubly linked list
 * @tail: pointer to the tail of a doubly linked list
 * @shaker: pointer to swapping node
 *
 * Return: void
 */

void swap_node_infront(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *temp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = temp;
	else
		*list = temp;

	temp->prev = (*shaker)->prev;
	(*shaker)->next = temp->next;

	if (temp->next != NULL)
		temp->next->prev = *shaker;
	else
		*tail = *shaker;

	(*shaker)->prev = temp;
	temp->next = *shaker;
	*shaker = temp;
}

/**
 * swap_node_back - swaps a doubly linked list in a backward manner
 *
 * @list: list to sort
 * @tail: tail of a doubly linked list
 * @shaker: current node, one to swap
 *
 * Return: void
 */

void swap_node_back(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *temp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = temp;
	else
		*tail = temp;

	temp->next = (*shaker)->next;
	(*shaker)->prev = temp->prev;

	if (temp->prev != NULL)
		temp->prev->next = *shaker;
	else
		*list = *shaker;

	(*shaker)->next = temp;
	temp->prev = *shaker;
	*shaker = temp;
}

/**
 * cocktail_sort_list - sorts a list using cocktail algorithm
 *
 * @list: doubly linked list to sort
 *
 * Return: void
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	unsigned int shaken_unstirred = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL; tail = tail->next)
		;
	while (shaken_unstirred == 0)
	{
		shaken_unstirred = 1;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_node_infront(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_unstirred = 0;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
		     shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_node_back(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_unstirred = 0;
			}
		}
	}
}
