#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */

typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void swap(int *a, int *b);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quicksort_recursive(int *array, int low, int high, size_t size);
int get_pivot(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_node_infront(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_back(listint_t **list, listint_t **tail, listint_t **shaker);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		  size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void heap_sort(int *array, size_t size);
void heapify(int *array, int n, int i, int size);
void radix_sort(int *array, size_t size);
int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void bitonic_sort(int *array, size_t size);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq, int flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, int flow);
void quick_sort_hoare(int *array, size_t size);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_recursion(int *array, size_t size, int left, int right);

#endif /* #ifndef SORT_H */
