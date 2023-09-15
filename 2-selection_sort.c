#include "sort.h"
/**
 * selection_sort - Function that sorts an array of integers in ascending 
 * order using the Selection sort algorithm.
 * @array: The array.
 * @size: The size of the array.
*/
void selection_sort(int *array, size_t size)
{
	size_t i = 0, min_a = 0, p, g = 0;

	if (!array)
	{
		return;
	}
	for (; i < size; i++)
	{
		min_a = i;
		for (p = (i + 1); p < size; p++)
		{
			if (array[min_a] > array[p])
			{
				min_a = p;
			}
		}
		if (min_a)
		{
			g = array[i];
			array[i] = array[min_a];
			array[min_a] = g;
			print_array(array, size);
		}
		else
		{
			continue;
		}
	}
}