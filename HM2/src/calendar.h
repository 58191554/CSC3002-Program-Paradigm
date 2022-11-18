/*
 * File: calendar.h
 * ----------------
 * This interface exports some useful types and functions for working
 * with calendar data.
 */

#ifndef _calendar_h
#define _calendar_h

#include <string>
#include "strlib.h"
/*
 * Type: Month
 * -----------
 * This enumerated type defines constant names for the months.  To be
 * consistent with conventional usage, the internal value for JANUARY
 * is 1 rather than 0.
 */

enum Month {
   JANUARY = 1,
   FEBRUARY,
   MARCH,
   APRIL,
   MAY,
   JUNE,
   JULY,
   AUGUST,
   SEPTEMBER,
   OCTOBER,
   NOVEMBER,
   DECEMBER
};

/*
 * Function: monthToString
 * Usage: string str = monthToString(month);
 * -----------------------------------------
 * Returns the name of the specified month as a string.  The name
 * appears entirely in uppercase, just as the constant names do.
 *
 * The monthToString function must return some value if the month does not
 * match any of the enumeration constants. Here, as in the Direction
 * type, the function returns ???.
 */

std::string monthToString(Month month);

/*
 * Function: daysInMonth
 * Usage: int nDays = daysInMonth(month, year);
 * --------------------------------------------
 * Returns the number of days in the specified month and year.
 */

int daysInMonth(Month month, int year);

/*
 * Function: isLeapYear
 * Usage: if (isLeapYear(year)) . . .
 * ----------------------------------
 * Returns true if the specified year is a leap year.
 */

bool isLeapYear(int year);



/*
 * Operator: ++
 * Usage: month++
 * --------------
 * Overloads the suffix version of the ++ operator to work with Month values.
 * The sole purpose of this definition is to support the idiom
 *
 *    for (Month month = JANUARY; month <= DECEMBER; month++) . . .
 */

Month operator++(Month & month, int);

/*
 * Class: Date
 * -----------
 * This class represents a date with a day, month, and year.
 */

class Date {

public:

/*
 * Constructor: Date
 * Usage: Date()
 *        Date(month, day, year);
 *        Date(day, month, year);
 * ------------------------------
 * Creates a Date object from its components.  The month must be specified
 * using one of the enumerated constants, which allows the compiler to
 * accept the day and month parameters in either order.  The constructor
 * generates an error if the date does not exist.
 */

   Date();
   Date(int day, Month month, int year);
   Date(Month month, int day, int year);

/*
 * Method: getDay
 * Usage: int day = date.getDay();
 * -------------------------------
 * Returns the day of the month.
 */

   int getDay();

/*
 * Method: getMonth
 * Usage: Month month = date.getMonth();
 * -------------------------------------
 * Returns the month.
 */

   Month getMonth();

/*
 * Method: getYear
 * Usage: int year = date.getYear();
 * ---------------------------------
 * Returns the year.
 */

   int getYear();

/*
 * Method: toString
 * Usage: string str = date.toString();
 * ------------------------------------
 * Returns the string representation of the date in the form dd-mmm-yyyy
 * where dd is the numeric date, mmm is the three-letter abbreviation of
 * the month, and yyyy is the four-digit numeric year.  The date of the
 * Apollo 11 moon landing would therefore be represented as "20-Jul-1969".
 */

   std::string toString();
   int getDayInYear();

private:

/* Instance variables */

   int day;             /* Day of the month              */
   Month month;         /* Enumerated type for the month */
   int year;            /* Four-digit numeric year       */
   int dayInYear;       /* Index of the day in the year  */

/* Private method prototypes */

   void initDate(int dd, Month mm, int yyyy);
   std::string capitalize(std::string str);

/* Friend declarations */

  friend Date operator+(Date, int);
  friend int operator-(Date d1, Date d2);

};

/*
 * Operator: <<
 * ------------
 * Overloads the << operator so that it is able to display Date values.
 */

std::ostream & operator<<(std::ostream & os, Date date);

/*
 * Operators: +, -
 * ---------------
 * Overloads these operators so that they work with Date objects.
 */

Date operator+(Date date, int delta);
Date operator-(Date date, int delta);
int operator-(Date d1, Date d2);

/*
 * Operators: +=, -=
 * -----------------
 * Overloads the shorthand assignment operators to work with Date objects.
 */

Date & operator+=(Date & date, int delta);
Date & operator-=(Date & date, int delta);

/*
 * Operators: ++, --
 * -----------------
 * Overloads the increment/decrement operators to work with Date objects.
 */

Date operator++(Date & date);
Date operator++(Date & date, int);
Date operator--(Date & date);
Date operator--(Date & date, int);

/*
 * Operators: ==, !=, <, <=, >, >=
 * -------------------------------
 * Overloads the relational operators to work with Date objects.
 */

bool operator==(Date d1, Date d2);
bool operator!=(Date d1, Date d2);
bool operator<(Date d1, Date d2);
bool operator<=(Date d1, Date d2);
bool operator>(Date d1, Date d2);
bool operator>=(Date d1, Date d2);

#endif
