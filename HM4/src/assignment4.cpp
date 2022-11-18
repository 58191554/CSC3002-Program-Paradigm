#include <iostream>
#include "console.h"
#include "assignment4.h"
using namespace std;

int main(){

    cout<<"--------HFractal test--------"<<endl;
    test1();
    cout<<"--------KnightsTour test--------"<<endl;
    test2();
    cout<<"--------MergeSort test--------"<<endl;
    test3();
    cout<<"--------SimpleTextEditor test--------"<<endl;
    test4();

    return 0;
}

int test1() {
   GWindow gw;
   double xc = gw.getWidth() / 2;
   double yc = gw.getHeight() / 2;
   cout << xc << yc << endl;
   drawHFractal(gw, xc, yc, 100, 3);
   return 0;
}

int test2() {
   solveKnightsTour(8,8);
   return 0;
}

int test3() {
   int array[] = { 56, 25, 37, 58, 95, 19, 73, 30 };
   sort(array, 8);
   printArray(array, 8);
   return 0;
}

int test4() {
   EditorBuffer buffer;
   while (true) {
      string cmd = getLine("*");
      if (cmd != "") executeCommand(buffer, cmd);
   }
   return 0;
}
