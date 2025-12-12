#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort
 * @list: Pointer to the head pointer of the list
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		tmp = current;

		while (tmp->prev && tmp->prev->n > tmp->n)
		{
			tmp->prev->next = tmp->next;
			if (tmp->next)
				tmp->next->prev = tmp->prev;

			tmp->next = tmp->prev;
			tmp->prev = tmp->next->prev;

			if (tmp->prev)
				tmp->prev->next = tmp;
			else
				*list = tmp;

			tmp->next->prev = tmp;

			print_list(*list);
		}
		current = current->next;
	}
}
