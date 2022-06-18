#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t idx = 0, i, index;
	int tmp = 0;

	if (!array || !size)
	{
		return;
	}
	while (idx < size)
	{
		tmp = array[idx];
		for (i = idx + 1; i < size; i++)
		{
			if (array[i] < tmp)
			{
				tmp = array[i];
				index = i;
			}
		}
		if (tmp != array[idx])
		{
			array[index] = array[idx];
			array[idx] = tmp;
			print_array(array, size);
		}
		idx++;
	}
}
