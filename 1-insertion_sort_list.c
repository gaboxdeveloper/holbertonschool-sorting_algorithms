#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order
 *
 * @list: A pointer to a pointer to the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		prev = current->prev;
		while (prev != NULL && prev->n > current->n)
		{
			if (prev->prev != NULL)
				prev->prev->next = current;
			current->prev = prev->prev;
			prev->prev = current;
			prev->next = current->next;
			current->next = prev;
			if (prev->next != NULL)
				prev->next->prev = prev;

			if (current->prev == NULL)
				*list = current;

			print_list(*list);

			prev = current->prev;
		}
		current = current->next;
	}
}
