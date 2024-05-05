#include "sort.h"

/**
 * quick_sort - A function that sorts an array of integers in ascending
 *	order using the Quick sort algorithm
 * @array: The array to br sorted
 * @size: The size of the array to be sorted
 *
 * Description: Implement the Lomuto partition scheme. Pivot should
 *	always be the last element of the partition being sorted
 *	Print the list after each swap.
 *
 * Return: Nothing.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, 0, size - 1, size);
}

/**
 * lomuto_sort - A function that uses the lomuto partition scheme to
 *	sort an array recursively.
 * @array: The array to be sorted.
 * @hi: The highest index of the array
 * @lo: The lowest index of the array
 * @size: The size of the array
 *
 * Description: Implement the lomuto partition scheme
 *
 * Return: Void.
 */
void lomuto_sort(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = lomuto_partition(array, lo, hi, size);
		lomuto_sort(array, lo, p - 1, size);
		lomuto_sort(array, p + 1, hi, size);
	}
}

/**
 * lomuto_partition - A function that uses pivot to partition an array
 * @array: The array to partition
 * @lo: The lowest index of the array
 * @hi: The highest index of the array
 * @size: The size of the array
 *
 * Description: The lomuto partition uses a pivot point
 *
 * Return: Index of the pivot element in the array.
 */
int lomuto_partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int u = lo - 1, v;

	for (v = lo; v <= hi; v++)
	{
		if (array[v] <= pivot)
		{
			u++;
			if (u != v)
			{
				swap(&array[u], &array[v]);
				print_array(array, size);
			}
		}
	}
	if (u > pivot)
	{
		swap(&array[u], &pivot);
		print_array(array, size);
	}
	return (u);
}

/**
 * swap - A function that swap position of two integers in an array.
 * @i: First integer to swap
 * @j: Second integer to swap
 *
 * Return: void.
 */
void swap(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}
