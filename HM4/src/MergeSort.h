#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
using namespace std;

/* Function prototypes */

/*
 * Function: sort
 * Usage: sort(array, n);
 * ----------------------
 * Sorts the first n elements of the vector into increasing order using
 * the merge sort algorithm, which consists of the following steps:
 *
 * 1. Copy the array into an array allocated on the stack.
 * 2. Divide the new array into two halves by manipulating the indices.
 * 3. Sort each half of the array recursively
 * 4. Merge the two halves back into the original one.
 */
void sort(int array[], int n);
void printArray(int array[], int n);

#endif // MERGESORT_H
