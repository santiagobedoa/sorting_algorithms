#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	int tmp;

	if (!array || !size)
	{
		return;
	}
	while (i < size)
	{
		for (j = 0; j < (size - i - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
		i++;
	}
}
