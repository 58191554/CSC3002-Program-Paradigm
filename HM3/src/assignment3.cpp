/*
 * File: TestIntArray.cpp
 * ----------------------
 * Tests the IntArray class.
 */
#include "assignment3.h"
#include "GymnasticsJudge.h"
#include "intarray.h"
#include "console.h"
using namespace std;


int main(){

    cout<<"Problem1 test:"<<endl;
    P1_test();
    cout<<"Problem2_a test:"<<endl;
    P2a_test();
    cout<<"Problem2_b test:"<<endl;
    P2b_test();
    cout<<"Problem2_c test:"<<endl;
    P2c_test();
    cin.ignore();
    return 0;
}


/* Test program */

int P1_test() {
   double scores[MAX_JUDGES];
   int nJudges = readScores(scores,MAX_JUDGES);
   if (nJudges < 3) {
      cout << "You must enter scores for at least three judges." << endl;
   } else {
      double total = sumArray(scores, nJudges);
      double smallest = findSmallest(scores, nJudges);
      double largest = findLargest(scores, nJudges);
      double average = (total - smallest - largest) / (nJudges - 2);
      cout << "The average after eliminating "
           << fixed << setprecision(2) << smallest << " and "
           << setprecision(2) << largest << " is "
           << setprecision(2) << average << "." << endl;
   }
   return 0;
}


/*
 * Function: test
 * Usage: test(str, value, expected);
 * ----------------------------------
 * Generates a line of test output, making sure that the value of value
 * is equal to the expected parameter.
 */
void test(string str, int value, int expected) {
   cout << str << " -> " << value;
   if (value != expected) cout << " (should be " << expected << ")";
   cout << endl;
}

int P2a_test() {
   IntArray array(5);
   test("array.size()", array.size(), 5);
   for (int i = 0; i < 5; i++) {
      test("array.get(" + integerToString(i) + ")", array.get(i), 0);
      cout << "array.put(" << i << ", " << i << ");" << endl;
      array.put(i, i);
      test("array.get(" + integerToString(i) + ")", array.get(i), i);
   }
   return 0;
}

int P2b_test() {
   IntArray array(5);
   test("array.size()", array.size(), 5);
   for (int i = 0; i < 5; i++) {
      test("array[" + integerToString(i) + "]", array[i], 0);
      cout << "array[" << i << "] = " << i << ";" << endl;
      array[i] = i;
      test("array[" + integerToString(i) + "]", array[i], i);
   }
   return 0;
}

int P2c_test() {
   IntArray v1(5);
   test("v1.size()", v1.size(), 5);
   for (int i = 0; i < 5; i++) {
      test("v1[" + integerToString(i) + "]", v1[i], 0);
      cout << "v1[" << i << "] = " << i << ";" << endl;
      v1[i] = i;
      test("v1[" + integerToString(i) + "]", v1[i], i);
   }
   IntArray v2;
   v2 = v1;
   test("v2.size()", v2.size(), 5);
   for (int i = 0; i < 5; i++) {
      test("v2[" + integerToString(i) + "]", v2[i], i);
   }
   return 0;
}
