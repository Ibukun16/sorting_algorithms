#ifndef SORT_HEADER
#define SORT_HEADER

#include <stdio.h>
#include <stdlib.h>

/* Comparison direction macros for bitonic sort */
#define UP 0
#define DOWN 1

/**
 * enum bool - Enumeration of boolean values.
 * @false: Equals 0.
 * @true: Equals 1.
 */
typedef enum bool
{
	false = 0,
	true
} bool;

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

/* Helper functions for printing */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Sort algorithms Below */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void swap_nodes(listint_t **head, listint_t **node1, listint_t *node2);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
int lomuto_partition(int *array, int lo, int hi, size_t size);
void swap_it(int *i, int *j);
void lomuto_sort(int *array, int lo, int hi, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_front_node(listint_t **head, listint_t **tail, listint_t **shaker);
void swap_back_node(listint_t **head, listint_t **tail, listint_t **shaker);
void counting_sort(int *array, size_t size);
int find_max(int *array, int size);
void merge_sort(int *array, size_t size);
void merge_sub(int *ar_inarr, int *b, size_t front, size_t middle, size_t rear);
void recursive_merge_sort(int *ar_inarr, int *tmp, size_t front, size_t back);

#endif /** SORT_HEADER **/

