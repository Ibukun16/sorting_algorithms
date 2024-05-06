#include "sort.h"

/**
 * shell_sort - A function that sort array of integers using Knuth sequence
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: void.
 */
void shell_sort(int *array, size_t size)
{
	size_t n = 1, a, b;
	int aux;

	if (array == NULL || size < 2)
		return;

	while (n  < (size / 3))
		n = n * 3 + 1;
	for (; n > 0; n /= 3)
	{
		for (a = n; a < size; a++)
		{
			aux = array[a];
			for (b = a; b >= n && array[b - n] > aux; b -= n)
				array[b] = array[b - n];
			array[b] = aux;
		}
		print_array(array, size);
	}
}
