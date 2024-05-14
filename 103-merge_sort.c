#include "sort.h"

/**
 * merge_sort - Sort an array of integer in ascending
 *		order using Merge sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Description: Implement the top-down merge sort algorithm
 */
void merge_sort(int *array, size_t size)
{
	int *mem;

	if (array == NULL || size < 2)
		return;

	mem = malloc(sizeof(int) * size);
	if (mem == NULL)
		return;

	recursive_merge_sort(array, mem, 0, size);
	free(mem);
}

/**
 * recursive_merge_sort - Uses recursion for the merge sort algorithm.
 * @ar_inarr: A subarray of an array of integers to sort.
 * @tmp: A buffer to store the sorted array.
 * @rear: The rear index of the subarray.
 * @front: The front index of the subarray.
 *
 * Return: Void.
 */
void recursive_merge_sort(int *ar_inarr, int *tmp, size_t front, size_t rear)
{
	size_t middle;

	if (rear > front + 1)
	{
		middle = rear - (rear - front) / 2;
		recursive_merge_sort(ar_inarr, tmp, front, middle);
		recursive_merge_sort(ar_inarr, tmp, middle, rear);
		merge_sub(ar_inarr, tmp, front, middle, rear);
	}
}

/**
 * merge_sub - Sort the integers in the the subarry.
 * @ar_inarr: The subarray of integers to sort.
 * @b: The buffer storing the sorted subarray.
 * @front: The index of the front array.
 * @middle: The index of the middle array.
 * @rear: The index of the rear array.
 *
 * Return: void
 */
void merge_sub(int *ar_inarr, int *b, size_t front, size_t middle, size_t rear)
{
	size_t x, y, z = 0;

	printf("Merging...\n[left]: ");
	print_array(ar_inarr + front, middle - front);

	printf("[right]: ");
	print_array(ar_inarr + middle, rear - middle);

	for (x = front, y = middle; x < middle && y < rear; z++)
		b[z] = (ar_inarr[x] < ar_inarr[y]) ? ar_inarr[x++] : ar_inarr[y++];
	for (; x < middle; x++)
		b[z++] = ar_inarr[x];
	for (; y < rear; y++)
		b[z++] = ar_inarr[y];
	for (x = front, z = 0; x < rear; x++)
		ar_inarr[x] = b[z++];

	printf("[Done]: ");
	print_array(ar_inarr + front, rear - front);
}
