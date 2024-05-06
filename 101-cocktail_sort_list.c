#include "sort.h"

/**
 * cocktail_sort_list - A function that sort a doubly linked list
 *	of integers in an ascending order using cocktail shaker algorithm.
 * @list: The doubly linked list to be so sorted.
 *
 * Description: Print the list after each swap and write the big O  notation.
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (tail = *list; tail->next;)
		tail = tail->next;
	while (not_stirred == false)
	{
		not_stirred = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_front_node(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				not_stirred = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list; shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_back_node(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				not_stirred = false;
			}
		}
	}
}

/**
 * swap_front_node - A function that swap a current active node in a listint_t
 *	doubly-linked list with the front node in the same list.
 * @head: A pointer to the head of the doubly-linked list of intergers.
 * @shaker: A pointer to the current node of the shaker algorithm.
 * @tail: A pointer to the tail of the doubly-linked list of integers
 *
 * Return: void
 */
void swap_front_node(listint_t **head, listint_t **tail, listint_t **shaker)
{
	listint_t *aux = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = aux;
	else
		*head = aux;
	aux->prev = (*shaker)->prev;
	(*shaker)->next = aux->next;
	if (aux->next != NULL)
		aux->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = aux;
	aux->next = *shaker;
	*shaker = aux;
}

/**
 * swap_back_node - A function that swap the current active node in a listint_t
 *	doubly-linked list of integers with the back node in the same list.
 * @head: A pointer to the head of the doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list of integers.
 * @shaker: A pointer to the active node of the cocktail shaker algorithm.
 *
 * Return: void.
 */
void swap_back_node(listint_t **head, listint_t **tail, listint_t **shaker)
{
	listint_t *aux = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = aux;
	else
		*tail = aux;
	aux->next = (*shaker)->next;
	(*shaker)->prev = aux->prev;
	if (aux->prev != NULL)
		aux->prev->next = *shaker;
	else
		*head = *shaker;
	(*shaker)->next = aux;
	aux->prev = *shaker;
	*shaker = aux;
}
