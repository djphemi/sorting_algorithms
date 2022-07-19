#include "sort.h"

/**
 * swap - that sorts a doubly linked list of integers
 * @array: pointers array
 * @size: size value the lengeth
 * @a: integer data
 * @b: integer data
 */
void swap(int *array, size_t size, int *a, int *b)
{
	int temp;

		temp = *a;
		*a = *b;
		*b = temp;
		print_array(array, size);
}
/**
 * heap_search - search point in doubly linked
 * @array: pointers array
 * @size: size value the lengeth
 * @down: integer data
 * @root: integer data
 */
void heap_search(int *array, size_t size, size_t down, size_t root)
{
	size_t child_left, child_right, max;

	max = root;
	child_left = 2 * max + 1;
	child_right = 2 * max + 2;

	if (child_left < down && array[child_left] > array[max])
		max = child_left;

	if (child_right < down && array[child_right] > array[max])
		max = child_right;

	if (max != root)
	{
		swap(array, size, array + root, array + max);
		heap_search(array, size, down, max);
	}
}

/**
 * heap_sort - function merge swap
 * @array: pointers array
 * @size: size value the lengeth
 */
void heap_sort(int *array, size_t size)
{
	int index;

	if (!array || size < 2)
		return;

	for (index = size / 2 - 1; index >= 0; index--)
		heap_search(array, size, size, index);

	for (index = size - 1; index > 0; index--)
	{
		swap(array, size, array + 0, array + index);
		heap_search(array, size, index, 0);
	}
}
