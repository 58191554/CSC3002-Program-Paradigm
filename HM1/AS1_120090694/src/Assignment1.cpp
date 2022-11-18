/*
 * CS 106B/X Sample Project
 * last updated: 2018/09/19 by Marty Stepp
 *
 * This project helps test that your Qt Creator system is installed correctly.
 * Compile and run this program to see a console and a graphical window.
 * If you see these windows, your Qt Creator is installed correctly.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "filelib.h"     // promptUserForFile
#include "console.h"
#include "Assignment1.h"
using namespace std;

/* Constants */

const int MAX = 6;

int main() {

    cout<<"Problem 1:"<<endl;
    TestCombinatorics();

    cout<<"Problem 2:"<<endl;
    TestFindDNAMatch();

    cout<<"Problem 3:"<<endl;
    TestRemoveComments();

    cout<<"Problem 4:"<<endl;
    TestBanishLetters();

    return 0;
}

void TestCombinatorics(){
    cout << "   n   k   P(n, k)   C(n, k)" << endl;
    for (int n = 0; n <= MAX; n++) {
       for (int k = 0; k <= n; k++) {
          cout << setw(4) << n;
          cout << setw(4) << k;
          cout << setw(9) << permutations(n, k);
          cout << setw(9) << combinations(n, k);
          cout << endl;
       }
    }
}

void TestFindDNAMatch(){
    cout<<"first case:"<<endl;
    findAllMatches("TTGCC", "TAACGGTACGTC");
    cout<<"second case:"<<endl;
    findAllMatches("TGC", "TAACGGTACGTC");
    cout<<"third case:"<<endl;
    findAllMatches("CCC", "TAACGGTACGTC");
}

void TestRemoveComments(){
    ifstream infile("hello.cpp");
    //promptUserForFile(infile);
    removeComments(infile, cout);
}

void TestBanishLetters(){
    banishLetters();
}


