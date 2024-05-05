#include "sort.h"

/**
 * selection_sort - A functionn that sort an array of integers
 *	in ascending order using the selection sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array.
 *
 * Description: Print the array after each swap
 *
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	int *smallest, n;
	size_t x, y;

	if (array == NULL || size < 2)
		return;

	for (x = 0; x < size - 1; x++)
	{
		smallest = array + x;
		for (y = x + 1; y < size; y++)
			smallest = (array[y] < *smallest) ? (array + y) : smallest;

		if ((array + x) != smallest)
		{
			n = *smallest;
			*smallest = array[x];
			array[x] = n;
			print_array(array, size);
		}
	}
}
