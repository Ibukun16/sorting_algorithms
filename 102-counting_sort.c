#include "sort.h"

/**
 * counting_sort - A function that sorts an array of integers in
 *		ascending order using Counting sort algorithm.
 * @array: The array of integers to be sorted
 * @size: The size of the array
 *
 * Description: Print cthe counting array once it is set up
 */
void counting_sort(int *array, size_t size)
{
	int *c, *mem, max, n;

	if (array == NULL || size < 2)
		return;
	mem = malloc(sizeof(int) * size);
	if (mem == NULL)
		return;
	max = find_max(array, size);
	c = malloc(sizeof(int) * (max + 1));
	if (c == NULL)
	{
		free(mem);
		return;
	}
	for (n = 0; n < (max + 1); n++)
		c[n] = 0;
	for (n = 0; n < (int)size; n++)
		c[array[n]] += 1;
	for (n = 0; n < (max + 1); n++)
		c[n] += c[n - 1];
	print_array(c, max + 1);

	for (n = 0; n < (int)size; n++)
	{
		mem[c[array[n]] - 1] = array[n];
		c[array[n]] -= 1;
	}
	for (n = 0; n < (int)size; n++)
		array[n] = mem[n];
	free(mem);
	free(c);
}

/**
 * find_max - A function that obtains the maximum value
 *		in an array of integers.
 * @array: The array of integers
 * @size: The size of the array
 *
 * Return: The maximum integer value in the array
 */
int find_max(int *array, int size)
{
	int max, x;

	for (max = array[0], x = 1; x < size; x++)
	{
		if (array[x] > max)
			max = array[x];
	}
	return (max);
}
