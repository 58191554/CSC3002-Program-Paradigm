/*
 * File: bigint.h
 * --------------
 * This interface exports the BigInt class, which makes it possible to
 * represent nonnegative integers of arbitrary magnitude.
 */

#ifndef _bigint_h
#define _bigint_h

#include <string>

class BigInt {

public:

/*
 * Constructor: BigInt
 * Usage: BigInt big(str);
 * -----------------------
 * Creates a new BigInt from a string of decimal digits.
 */

   BigInt(std::string str);

/*
 * Destructor: ~BigInt
 * -------------------
 * Frees the memory used by a BigInt when it goes out of scope.
 */

   ~BigInt();

/*
 * Method: toString
 * Usage: string str = bigint.toString();
 * --------------------------------------
 * Converts a BigInt object to the corresponding string.
 */

   std::string toString() const;

   BigInt operator+(const BigInt & b2) const;
   BigInt operator*(const BigInt & b2) const;

/* Private section */

/*
 * Implementation notes: BigInt data structure
 * -------------------------------------------
 * The BigInt data structure stores the digits in the number in
 * a linked list in which the digits appear in reverse order with
 * respect to the items in the list.  Thus, the number 1729 would
 * be stored in a list like this:
 *
 *     start
 *    +-----+    +-----+    +-----+    +-----+    +-----+
 *    |  o--+--->|  9  |  ->|  2  |  ->|  7  |  ->|  1  |
 *    +-----+    +-----+ /  +-----+ /  +-----+ /  +-----+
 *               |  o--+-   |  o--+-   |  o--+-   | NULL|
 *               +-----+    +-----+    +-----+    +-----+
 *
 * The sign of the entire number is stored in a separate instance
 * variable, which is -1 for negative numbers and +1 otherwise.
 * Leading zeros are not stored in the number, which means that
 * the representation for zero is an empty list.
 */

private:

/*
 * Type: Cell
 * ----------
 * This structure type holds a single digit in the linked list.
 */

   struct Cell {
      Cell *leadingDigits;
      int finalDigit;
   };

/* Instance variables */

   Cell *start;          /* Linked list of digits */

/* Private methods */

   BigInt(Cell *digits) {
      start = digits;
   }

   static Cell *digitCons(Cell *leadingDigits, int finalDigit) {
      Cell *cp = new Cell;
      cp->leadingDigits = leadingDigits;
      cp->finalDigit = finalDigit;
      return cp;
   }

   static Cell *leadingDigits(Cell *n) {
      return (n == NULL) ? NULL : n->leadingDigits;
   }

   static int finalDigit(Cell *n) {
      return (n == NULL) ? 0 : n->finalDigit;
   }

   static Cell *addWithCarry(Cell *n1, Cell *n2, int carry) {
      Cell *p1 = leadingDigits(n1);
      Cell *p2 = leadingDigits(n2);
      int sum = finalDigit(n1) + finalDigit(n2) + carry;
      if (sum == 0 && p1 == NULL && p2 == NULL) return NULL;
      return digitCons(addWithCarry(p1, p2, sum / 10), sum % 10);
   }

   static Cell *mulStep(Cell *n1, Cell *n2) {
      if (n1 == NULL) return NULL;
      return addWithCarry(mulDigit(finalDigit(n1), n2),
                          mulStep(leadingDigits(n1), digitCons(n2, 0)), 0);
   }

   static Cell *mulDigit(int digit, Cell *n) {
      if (digit == 0) return NULL;
      return addWithCarry(n, mulDigit(digit - 1, n), 0);
   }

};

#endif
