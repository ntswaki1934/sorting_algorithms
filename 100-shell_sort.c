#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * @array: the array to be sorted
 * @size: the size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	/* Start with the largest gap and reduce it by a factor of 3 each iteration */
	for (gap = 1; gap < size / 3; gap = gap * 3 + 1)
		;

	/* Loop until gap becomes 0 */
	while (gap > 0)
	{
	/* Loop from gap to the end of the array */
	for (i = gap; i < size; i++)
	{
	/* Store the current element in temp */
	temp = array[i];

	/* Shift elements that are greater than temp by gap positions to the right */
	for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
		array[j] = array[j - gap];

	/* Put temp in its correct position */
		array[j] = temp;
	}

	/* Print the array after each gap reduction */
	print_array(array, size);

	/* Reduce the gap by a factor of 3 */
	gap = (gap - 1) / 3;
	}
}
