#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	recursion_sort(array, 0, size - 1, size);
}

/**
 * recursion_sort - implements the Lomuto’s algorithm
 * @array: array to be sorted
 * @start: index of the first element of the array
 * @end: index of the last element of the array
 * @size: size of the array
 *
 * Return: void
 */
void recursion_sort(int *array, int start, int end, size_t size)
{
	int pivot;

	if (start < end)
	{
		pivot = partition(array, start, end, size);
		recursion_sort(array, start, pivot - 1, size);
		recursion_sort(array, pivot + 1, end, size);
	}
}

/**
 * partition - split the array
 * @array: array to be sorted
 * @start: index of the first element of the array
 * @end: index of the last element of the array
 * @size: size of the array
 *
 * Return: The pivot of the splited array
 */
int partition(int *array, int start, int end, size_t size)
{
	int j;
	int pivote = array[end];
	int tmp_pivote = start - 1;

	for (j = start; j <= end - 1; j++)
	{
		if (pivote >= array[j])
		{
			tmp_pivote++;
			swap(array, tmp_pivote, j, size);
		}
	}
	swap(array, tmp_pivote + 1, end, size);
	return (tmp_pivote + 1);
}

/**
 * swap - swap two elements of an array
 * @array: array to be swaped
 * @first: index of the first element
 * @second: index of the second element
 * @size: size of the array
 *
 * Return: void
 */
void swap(int *array, int first, int second, size_t size)
{
	int tmp = array[first];

	if (first != second)
	{
		array[first] = array[second];
		array[second] = tmp;
		print_array(array, size);
	}
}
