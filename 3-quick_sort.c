#include "sort.h"

static void quick_sort_recursive(int *array, int low, int high, size_t size);
static int lomuto_partition(int *array, int low, int high, size_t size);

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, (int)size - 1, size);
}

/**
 * quick_sort_recursive - Recursively sorts sub-arrays using Quick sort
 * @array: Array to sort
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 *
 * Return: Nothing
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
 * lomuto_partition - Partitions an array using the Lomuto scheme
 * @array: Array to partition
 * @low: Starting index of the partition
 * @high: Ending index of the partition (pivot)
 * @size: Size of the array
 *
 * Return: Final position of the pivot
 */
static int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, tmp;
	int i, j;

	pivot = array[high];
	i = low - 1;

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
