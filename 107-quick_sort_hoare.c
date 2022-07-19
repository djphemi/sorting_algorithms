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
 * hoare - partition scheme.
 * @array: pointer array in integers
 * @size: ssize with the array
 * @left: ssize with the array left
 * @right: int with the array right
 * Return: Always integers
 */
int hoare(int *array, ssize_t size, ssize_t left, ssize_t right)
{
	int pivot;
	ssize_t asc, des;

	pivot = array[right];
	for (asc = left - 1, des = right + 1; asc < des; )
	{
		do {
			asc++;
		} while (array[asc] < pivot);

		do {
			des--;
		} while (array[des] > pivot);

		if (asc < des)
			swap(array, size, array + asc, array + des);
	}
	return (asc);
}

/**
 * quick_sort_recursion - partition scheme.
 * @array: pointer array in integers
 * @size: ssize with the array
 * @left: ssize with the array left
 * @right: int with the array right
 */
void quick_sort_recursion(int *array, size_t size, ssize_t left, ssize_t right)
{
	ssize_t part;

	if (right > left)
	{
		part = hoare(array, size, left, right);
		quick_sort_recursion(array, size, left, part - 1);
		quick_sort_recursion(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - selection value in array
 * @array: pointers in integer
 * @size: value data
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_sort_recursion(array, size, 0, size - 1);
}
