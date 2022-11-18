/*
 * File: Assignment.cpp
 * ----------------------
 * This file tests the Problem 1, 2 and 3.
 */

#include <iostream>
#include "console.h"
#include "simpio.h"
#include "strlib.h"
#include "assignment2.h"
using namespace std;

int main() {
    cout<<"Problem 1:"<<endl;
    TestCalender();
    TestDateClass();
    TestDateOperator();
    cout<<"Problem 2:"<<endl;
    TestReverseQueue();
    cout<<"Problem 3:"<<endl;
    TestMorseCode();
    return 0;
}


/*******************Problem 1, part 1******************/
/* a sample INPUT: 2012
 * The OUTPUT: Enter a year: 2012
 *             JANUARY has 31 days.
 *             FEBRUARY has 29 days.
 *             ...... //(You need print all of them)
 *             DECEMBER has 31 days.
 */
void TestCalender(){
    int year;
    cout << "Enter a year: ";
    cin >> year;
    for (Month month = JANUARY; month <= DECEMBER; month = Month(month + 1)) {
       cout << monthToString(month) << " has " << daysInMonth(month, year)
            << " days." << endl;
    }
}
/*******************Problem 1, part 2******************/
/* Sample: Date moonLanding1(20, JULY, 1969);
 * OUTPUT: moonLanding1 = 20-Jul-1969
 * Sample: Date moonLanding2(JULY, 20, 1969);
 * OUTPUT: moonLanding2 = 20-Jul-1969
 */
void TestDateClass(){
    Date moonLanding(20, JULY, 1969);
    cout << "moonLanding = " << moonLanding.toString() << endl;
}
/*******************Problem 1, part 3******************/
/* Sample: Date moonLanding(20, JULY, 1969);
 *         Date kennedyAssassination(NOVEMBER, 22, 1963);
 *         Date newYearsEve(DECEMBER, 31, 2011);
 *         Date inaugurationDay(21, JANUARY, 2013);
 *         Date electionDay(6, NOVEMBER, 2012);
 *
 * OUTPUT: moonLanding = 20-Jul-1969
 *         kennedyAssassination = 22-Nov-1963
 *         moonLanding < kennedyAssassination = false
 *         moonLanding > kennedyAssassination = true
 *         moonLanding == kennedyAssassination = false
 *         moonLanding == moonLanding = true
 *         inaugurationDay - electionDay = 76
 *         New Year's Eve = 31-Dec-2011
 *         New Year's Day = 1-Jan-2012
 *         6-Nov-2012 //Print days from election day to inauguration day.
 *         7-Nov-2012
 *         ...... //(You need print all of them)
 *         21-Jan-2013
 */
void TestDateOperator(){
    Date moonLanding(20, JULY, 1969);
    Date kennedyAssassination(NOVEMBER, 22, 1963);
    Date newYearsEve(DECEMBER, 31, 2011);
    Date inaugurationDay(21, JANUARY, 2013);
    Date electionDay(6, NOVEMBER, 2012);
    cout << "moonLanding = " << moonLanding << endl;
    cout << "kennedyAssassination = " << kennedyAssassination << endl;
    cout << boolalpha;
    cout << "moonLanding < kennedyAssassination = "
         << (moonLanding < kennedyAssassination) << endl;
    cout << "moonLanding > kennedyAssassination = "
         << (moonLanding > kennedyAssassination) << endl;
    cout << "moonLanding == kennedyAssassination = "
         << (moonLanding == kennedyAssassination) << endl;
    cout << "moonLanding == moonLanding = "
         << (moonLanding == moonLanding) << endl;
    cout << "inaugurationDay - electionDay = "
         << (inaugurationDay - electionDay) << endl;
    Date day = newYearsEve;
    cout << "New Year's Day = " << day++ << endl;
    cout << "New Year's Day = " << day << endl;
    for (Date d = electionDay; d <= inaugurationDay; d++) {
       cout <<  d << endl;
    }
}

/*********************Problem 2*******************/
/* Using enqueue method to obtain a queue containing: Genesis Exodus Leviticus Numbers Deuteronomy
 * List the queue
 * Reverse the queue
 * List the queue
 * A sample OUTOUT: The queue contains: Genesis Exodus Leviticus Numbers Deuteronomy
 *                  The queue contains: Deuteronomy Numbers Leviticus Exodus Genesis
 */
int TestReverseQueue(){
    Queue<string> line;
    line.enqueue("Genesis");
    line.enqueue("Exodus");
    line.enqueue("Leviticus");
    line.enqueue("Numbers");
    line.enqueue("Deuteronomy");
    listQueue(line);
    reverseQueue(line);
    listQueue(line);
    return 0;
}

/*********************Problem 3*******************/
int TestMorseCode(){
    cin.ignore();
    cout << "Morse code translator" << endl;
    /* A sample translator:
     *                     > SOS
     *                     ... --- ...
     *                     > ... --- ...
     *                     SOS
     */
    while (true) {
       int i = 0, j = 0 ;
       std::cout << i++ << ++j;
       string line = getLine("> ");
       if (line == "") break;
       line = toUpperCase(line);
       if (line[0] == '.' || line[0] == '-') {
           cout << translateMorseToLetters(line) << endl;
       } else {
           cout << translateLettersToMorse(line) << endl;
       }
    }
    return 0;
}



