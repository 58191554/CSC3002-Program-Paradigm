// This header file doesn't do much, but it's good to demonstrate that it's
// possible to create and edit header files

#include <iostream>
#include <fstream>
using namespace std;

/* Function prototypes */

/*
 * Function: removeComments
 * Usage: removeComments(is, os);
 * ------------------------------
 * Copies characters from the input stream is to the output stream os,
 * removing any comments it finds.  This program eliminates both the
 * /* and // comment forms but does not check to see if those characters
 * are embedded within strings.
 */
void promptUserForFile(istream infile);
void removeComments(istream & is, ostream & os);
//ifstream promptUserForFile();
