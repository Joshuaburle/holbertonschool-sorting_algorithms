#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the selection sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 *
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[i])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
}
