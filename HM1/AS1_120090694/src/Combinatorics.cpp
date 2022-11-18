/*
 * File: Combinatorics.cpp
 * -----------------------
 * This file implements the combinatorics.h interface.
 */

#include "Combinatorics.h"
#include <iostream>

using namespace std;


int permutations(int n, int k){
    int result = 1;
    for (int i=n;i>=n-k+1;i--){
        result *= i;
    }
    return result;
}

int combinations(int n, int k){
    int result = permutations(n,k);
    for(int i = 1;i<=k;i++){
        result/=i;
    }
    return result;
}
