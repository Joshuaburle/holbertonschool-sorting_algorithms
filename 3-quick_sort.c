#include "sort.h"

static void quick_sort_recursive(int *array, int low, int high, size_t size);
static int lomuto_partition(int *array, int low, int high, size_t size);

/**
 * quick_sort - Sorts an array using quick sort (Lomuto)
 * @array: Array to sort
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, (int)size - 1, size);
}

/**
 * quick_sort_recursive - Recursive quick sort
 * @array: Array to sort
 * @low: Start index
 * @high: End index
 * @size: Size of array
 */
static void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, p - 1, size);
		quick_sort_recursive(array, p + 1, high, size);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: Array to partition
 * @low: Start index
 * @high: End index (pivot)
 * @size: Size of array
 *
 * Return: Pivot index
 */
static int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j, tmp;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}

	if (i + 1 != high)
	{
		tmp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}

	return (i + 1);
}
