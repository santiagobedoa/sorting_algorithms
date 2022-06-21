#include "sort.h"

/**
 * swap_nodes_cocktail - swaps two nodes in a doubly linked list
 * @list: double pointer to linked list
 * @node: node to swap
 *
 * Return: void
 */
void swap_nodes_cocktail(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
	{
		node->prev->next = node->next;
	}
	else
	{
		*list = node->next;
	}
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
	{
		node->next->prev = node;
	}
}

/**
 * cocktail_sort_list - sorts a doubly linked list of ints in ascending order
 * @list: list to be sorted
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *node = *list;

	if (*list == NULL || list == NULL)
	{
		return;
	}
	while (swapped != 0)
	{
		swapped = 0;
		while (node->next)
		{
			if (node->n > node->next->n)
			{
				swap_nodes_cocktail(list, node);
				swapped = 1;
				print_list(*list);
			}
			else
			{
				node = node->next;
			}
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (node->prev)
		{
			if (node->n < node->prev->n)
			{
				swap_nodes_cocktail(list, node->prev);
				swapped = 1;
				print_list(*list);
			}
			else
			{
				node = node->prev;
			}
		}
	}
}
