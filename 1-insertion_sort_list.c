#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @a: address of the first node
 * @b: address of the second node
 *
 * Return: void
 */
void swap_nodes(listint_t *a, listint_t *b)
{
	if (a->prev)
	{
		a->prev->next = b;
	}
	if (b->next)
	{
		b->next->prev = a;
	}
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}

/**
 * insertion_sort_list - sorts a doubly linked list of ints in ascending order
 * @list: doubly linked list to be ordered
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j;

	if (!list || !(*list) || !(*list)->next)
	{
		return;
	}
	i = *list;
	while (i)
	{
		j = i;
		while (j && j->prev)
		{
			if (j->prev->n > j->n)
			{
				swap_nodes(j->prev, j);
				if (!j->prev)
				{
					*list = j;
				}
				print_list((const listint_t *)*list);
			}
			else
			{
				j = j->prev;
			}
		}
		i = i->next;
	}
}
