#include "sort.h"

/**
 * insertion_sort_list - A function that sorts a doubly linked list
 *	of integers in ascending order using the insertion sort algorithm
 * @list: A pointer to the doubly linked list containing the set
 *	of integers to be sorted.
 *
 * Description: Print the list after each swap
 *
 * Return: Nothing.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *counter, *insert, *aux;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (counter = (*list)->next; counter != NULL; counter = aux)
	{
		aux = counter->next;
		insert = counter->prev;
		while (insert != NULL && counter->n < insert->n)
		{
			swap_nodes(list, &insert, counter);
			print_list((const listint_t *)*list);
		}
	}
}

/**
 * swap_nodes - A function that swap two nodes in a listint_t
 *	doubly-linked list.
 * @head: A pointer to the head of the doubly-linked list.
 * @node1: A pointer to the first node to be swapped
 * @node2: The second node to be swapped.
 */
void swap_nodes(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}
