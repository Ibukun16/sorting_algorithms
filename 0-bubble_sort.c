#include "sort.h"

/**
 * bubble_sort - A function that sort an array in ascending
 * order mimicking Bubble sort algorithm.
 * @array: The array containing the integers to be sorted.
 * @size: The size of the array.
 *
 * Description: Print the list after each swap
 *
 * Return: Nothing.
 */
void bubble_sort(int *array, size_t size)
{
	size_t x, y;

	if (array == NULL || size < 2)
		return;

	for (x = 0; x < size - 1; x++)
	{
		for (y = 0; y < size - x - 1; y++)
		{
			if (array[y] > array[y + 1])
			{
				swap_it(array + y, array + y + 1);
				print_array(array, size);
			}
		}
	}
}

/**
 * swap_it - A function that swap the position of two integers
 * @i: First element to swap
 * @j: Second element to swap
 *
 * Description: Swap the two integers given.
 *
 * Return: Void
 */
void swap_it(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}
