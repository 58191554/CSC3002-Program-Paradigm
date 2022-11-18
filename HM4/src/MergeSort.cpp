/*
 * File: MergeSort.cpp
 * -------------------
 * This file implements the merge sort algorithm using arrays rather
 * than vectors.
 */

#include "MergeSort.h"

/*
 * Function: printArray
 * Usage: printArray(array, n);
 * ----------------------------
 * Prints the elements of the array on a single line with the elements
 * enclosed in braces and separated by commas.
 */

void printArray(int array[], int n) {
   cout << "{ ";
   for (int i = 0; i < n; i++) {
      if (i > 0) cout << ", ";
      cout << array[i];
   }
   cout << " }" << endl;
}

void sort(int array[], int n){
    if (n<=1)   return;
    int array1[n/2];
    int array2[n-n/2];
    int k = 0;
    int l = 0;
    for (int i = 0; i<n; i++){
        if(i < n/2){
            array1[k++] = array[i];
        }
        else{
            array2[l++] = array[i];
        }
    }
    sort(array1, n/2);
    sort(array2, n-n/2);
    // merge(array, array1, array2);
    int p = 0;
    int p1 = 0;
    int p2 = 0;
    while(p1 < n/2 && p2 < n-n/2 ){
        if(array1[p1] < array2[p2]){
            array[p++] = array1[p1++];
        }
        else{
            array[p++] = array2[p2++];
        }
    }
    while(p1 < n/2) array[p++] = array1[p1++];
    while(p2 < n-n/2) array[p++] = array2[p2++];
}


