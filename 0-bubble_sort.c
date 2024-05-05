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
	int tmp;

	if (array == NULL || size < 2)
		return;
	for (x = 0; x < size - 1; x++)
	{
		for (y = 0; y < size - x - 1; y++)
		{
			if (array[y] > array[y + 1])
			{
				tmp = array[y];
				array[y] = array[y + 1];
				array[y + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
