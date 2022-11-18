/*
 * File: intarray.cpp
 * ------------------
 * This file inplements the intarray.h interface.
 */

#include "intarray.h"
int zero = 0;
IntArray::IntArray(int n){
    array = new int [n];
    for(int i = 0;i< n; i++){
        *(array+i) = 0;
    }
    nElements = n;
//    cout << "show array:"<< endl;
//    for(int i = 0;i<n ;i++){
//        cout << "*(array+" << to_string(i)<<")"<<*(array+i) << endl;
//    }
}

IntArray :: ~IntArray(){
    delete [] array;
}

int IntArray :: size(){
    return nElements;
}

int IntArray:: get(int index){
    if(index < nElements && index >=0){
        return array[index];
    }
    else{
        cout << "Error: Index out of range!!" << endl;
        return -1;
    }
}

void IntArray :: put(int index, int value){
    if (index < nElements && index >=0){
        array[index] = value;
    }
    else{
        cout << "Error: Index out of range!!" << endl;
    }
}

int & IntArray :: operator[](int index){
//    return array[index];
    if (index < nElements && index >=0){
        return array[index];
    }
    else{
        cout << "Error: index out of range";
        return zero;
    }
}

IntArray & IntArray :: operator=(const IntArray &src){
    if (this != &src){
        delete[] array;
        deepCopy(src);
    }
    return  *this;
}
void IntArray :: deepCopy(const IntArray & src){
    array = new int[src.nElements];
    for(int i = 0;i<src.nElements;i++){
        array[i] = src.array[i];
    }
    nElements = src.nElements;
}
