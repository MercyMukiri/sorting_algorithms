#include "deck.h"

/**
 * _strcmp - compares two strings
 *
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 if equal, positive value if s1 > s2, otherwise negative
 */

int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);

	return (0);
}

/**
 * get_value - gets the numerical value of a card
 *
 * @card: deck_node_t card
 *
 * Return: Numerical value of the card
 */

int get_value(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);

	return (13);
}

/**
 * insertion_sort_deck_kind - sorts a deck according to kind
 *
 * @deck: pointer to head of deck_node_t
 *
 * Return: void
 */

void insertion_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *iterate, *temp, *insert;

	for (iterate = (*deck)->next; iterate != NULL; iterate = temp)
	{
		temp = iterate->next;
		insert = iterate->prev;

		while (insert != NULL
		       && insert->card->kind > iterate->card->kind)
		{
			insert->next = iterate->next;

			if (iterate->next != NULL)
				iterate->next->prev = insert;

			iterate->prev = insert->prev;
			iterate->next = insert;

			if (insert->prev != NULL)
				insert->prev->next = iterate;
			else
				*deck = iterate;

			insert->prev = iterate;
			insert = iterate->prev;
		}
	}
}

/**
 * insertion_sort_deck_value - sort a deck according to value
 *
 * @deck: head of a deck_node_t
 *
 * Return: void
 */

void insertion_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *iterate, *insert, *temp;

	for (iterate = (*deck)->next; iterate != NULL; iterate = temp)
	{
		temp = iterate->next;
		insert = iterate->prev;

		while (insert != NULL &&
		       insert->card->kind == iterate->card->kind &&
		       get_value(insert) > get_value(iterate))
		{
			insert->next = iterate->next;
			if (iterate->next != NULL)
				iterate->next->prev = insert;

			iterate->prev = insert->prev;
			iterate->next = insert;

			if (insert->prev != NULL)
				insert->prev->next = iterate;
			else
				*deck = iterate;

			insert->prev = iterate;
			insert = iterate->prev;
		}
	}
}

/**
 * sort_deck - sorts a deck of cards from spades to diamonds and
 * from ace to kings
 *
 * @deck: pointer to the head of a deck_node_t
 *
 * return: void
 */

void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_deck_kind(deck);
	insertion_sort_deck_value(deck);
}
