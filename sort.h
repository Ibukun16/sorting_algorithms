#ifndef SORT_HEADER
#define SORT_HEADER

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void swap_nodes(listint_t **head, listint_t **node1, listint_t *node2);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
int lomuto_partition(int *array, int lo, int hi, size_t size);
void swap_it(int *i, int *j);
void lomuto_sort(int *array, int lo, int hi, size_t size);

#endif /** SORT_HEADER **/

