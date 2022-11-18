/*
 * File: Combinatorics.h
 * ---------------------
 * This interface exports functions for calculating permutations
 * and combinations.
 */

/* Function Prototypes */

/*
 * Function: permutations(n, k)
 * Usage: int n = permutations(n, k);
 * ----------------------------------
 * Returns the number of permutations of n objects taken k at a time.
 * In a permutation, the order of elements is important, so that the
 * combination AB represents a different permutation than BA.
 */

int permutations(int n, int k);

/*
 * Function: combinations(n, k)
 * Usage: int n = combinations(n, k);
 * ----------------------------------
 * Returns the number of combinations of n objects taken k at a time.
 * In a combination, the order of elements is ignored, so that the
 * combination AB is treated as the same combination as BA.
 */

int combinations(int n, int k);

