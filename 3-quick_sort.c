#include "sort.h"
/**
 * swap - Function that swap 2 positions in array.
 * @array: The array.
 * @a: The first value.
 * @b: The second value.
*/
void swap(int *array, int a, int b)
{
	size_t tmp = 0;

	tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
}
/**
 * Lomuto_P - Function with the Lomuto Partition Scheme.
 * @array: The array.
 * @low: The lowest value.
 * @high: The maximum value.
 * @size: The size of the array.
 * Return: index.
*/
int Lomuto_P(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int index = low - 1;
	int j;

	for (j = low; j <= high; j++)
	{
		if (array[j] <= pivot)
		{
			index++;
			if (index != j)
			{
				swap(array, index, j);
				print_array(array, size);
			}
		}
	}
	return (index);
}
/**
 * low_min - Function that gives the low - min value for Lomuto_P function.
 * @array: The array.
 * @low: The lowest value.
 * @high:The maximum value.
 * @size: The size of the array.
*/
void low_min(int *array, int low, int high, int size)
{
	int a = 0;

	if (low < high)
	{
		a = Lomuto_P(array, low, high, size);
		low_min(array, low, a - 1, size);
		low_min(array, a + 1, high, size);
	}
}
/**
 * quick_sort - Function that sorts an array of integers in ascending order
 * using the Quick sort algorithm.
 * @array: The array.
 * @size: The size of the array.
*/
void quick_sort(int *array, size_t size)
{
	if (!array)
	{
		return;
	}
	low_min(array, 0, (size - 1), size);
}
