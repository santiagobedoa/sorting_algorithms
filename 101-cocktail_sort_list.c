#include "sort.h"

/**
 * swap_nodes - swap 2 nodes in a doubly-linked list
 * @a: address of first node
 * @b: address of second node
 *
 * Return: void
 */
void swap_nodes(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}

/**
 * head_traverse - function that sorts from head to tail
 * @head: head of the list
 * @tail: tail fo the list
 * @list: original head of the list
 *
 * Return: new tail of the list
 */
listint_t *head_traverse(listint_t *head, listint_t *tail, listint_t *list)
{
	while (head && head->next)
	{
		if (head->n > head->next->n)
		{
			swap_nodes(head, head->next);
			if (head->prev->prev == NULL)
				list = head->prev;
			print_list(list);
		}
		else
			head = head->next;
		if (head->next == NULL)
			tail = head;
	}
	return (tail);
}


/**
 * tail_traverse - function that sorts from the tail back
 * @head: head of list
 * @tail: tail of the list
 * @list: original head of the list
 *
 * Return: new head of the list
 */
listint_t *tail_traverse(listint_t *head, listint_t *tail, listint_t *list)
{
	while (tail && tail->prev)
	{
		if (tail->n < tail->prev->n)
		{
			swap_nodes(tail->prev, tail);
			if (tail->prev == NULL)
				list = tail;
			print_list(list);
		}
		else
			tail = tail->prev;
		if (tail->prev == NULL)
			head = tail;
	}
	return (head);
}

/**
 * cocktail_sort_list - sorts linked list using cocktail shaker sort
 *
 * @list: doubly linked list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *head, *len;
	int i = 0, j = 0;

	if (!list || !*list)
		return;
	len = *list;
	for (i = 0; len; i++)
	{
		len = len->next;
	}
	if (i < 2)
		return;
	head = *list;
	while (j < i)
	{
		tail = head_traverse(head, tail, *list);
		head = tail_traverse(head, tail, *list);
		*list = head;
		j++;
	}
}
