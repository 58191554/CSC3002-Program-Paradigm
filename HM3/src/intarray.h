/*
 * File: intarray.h
 * ----------------
 * This interface file contains a simplified version of the Array
 * class in which the elements are always ints.
 */
#include "error.h"
#include "strlib.h"
using namespace std;

#ifndef _intarray_h
#define _intarray_h

/*
 * Class: IntArray
 * ---------------
 * This interface defines a simplified version of the Array class in
 * which the elements are always ints.  This implementation supports
 * the following methods:
 *
 * - A constructor IntArray(n) that creates an IntArray with n elements,
 *   each of which is initialized to 0.
 * - A destructor that frees any heap storage allocated by the IntArray.
 * - A method size() that returns the number of elements in the IntArray.
 * - A method get(k) that returns the element at index position k.  If k is
 *   not within the bounds of the array, the get method signals an error.
 * - A method put(k, value) that assigns value to the element at index
 *   position k.  If k is out of bounds, the put method signals an error.
 * - The operator [] as a shorthand for selection.
 */

class IntArray {

public:

/*
 * Constructor: IntArray
 * Usage: IntArray array(n);
 * -------------------------
 * The constructor initializes a new IntArray object with n elements,
 * each of which is initialized to 0.
 */

   IntArray(int n = 0);

/*
 * Destructor: ~IntArray
 * Usage: (usually implicit)
 * -------------------------
 * Frees the storage associated with this array.
 */

   ~IntArray();

/*
 * Method: size
 * Usage: nElems = array.size();
 * -----------------------------
 * Returns the number of elements in this array.
 */

   int size();

/*
 * Method: get
 * Usage: val = array.get(3);
 * --------------------------
 * Returns the element at the specified index in this array.
 * Elements are indexed starting with 0.  Signalsan error if
 * index is outside of the array bounds.
 */

   int get(int index);

/*
 * Method: put
 * Usage: array.put(3, value);
 * ---------------------------
 * Replaces the element at the specified index in this array with
 * a new value.  The previous value at that index is overwritten.
 * Signals an error if index is outside of the array bounds.
 */

   void put(int index, int value);

/*
 * Operator: []
 * Usage: array[index]
 *        array[index] = value;
 * ----------------------------
 * Returns the value in the specified index position of array.  The
 * result is returned by reference, which means that selection
 * expressions can be used on the left side of an assignment.
 */

   int & operator[](int index);

/*
 * Copy constructor: IntArray
 * Usage: usually implicit
 * -----------------------
 * Initializes the current object to be a deep copy of the specified source.
 */

   IntArray(const IntArray & src);

/*
 * Operator: =
 * Usage: dst = src;
 * -----------------
 *
 */

   IntArray & operator=(const IntArray & src);

private:

/* Instance variables */

   int *array;             /* The dynamic array holding the elements */
   int nElements;          /* The number of elements in the array    */

/* Private method prototype */

void deepCopy(const IntArray & src);

};

#endif
