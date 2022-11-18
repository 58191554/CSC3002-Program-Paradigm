/*
 * File: calendar.cpp
 * ------------------
 * This file implements the calendar.h interface
 */

#include "calendar.h"
// TODO
using namespace std;

//Build the monthToString
string abbr(Month month);       //Declearation a new function

string monthToString(Month month){
    switch (month) {
        case(1): return "JANUARY"; break;
        case(2): return "FEBRUARY"; break;
        case(3): return "MARCH"; break;
        case(4): return "APRIL"; break;
        case(5): return "MAY"; break;
        case(6): return "JUNE"; break;
        case(7): return "JULY"; break;
        case(8): return "AUGUST"; break;
        case(9): return "SEPTEMBER"; break;
        case(10): return "OCTOBER"; break;
        case(11): return "NOVEMBER"; break;
        case(12): return "DECEMBER"; break;
    }
    return "";
}

int daysInMonth(Month month, int year){
    switch (month) {
        case(1): return 31; break;
        case(2):
            if (isLeapYear(year))
                return 29;
            else
                return 28;
        case(3): return 31; break;
        case(4): return 30; break;
        case(5): return 31; break;
        case(6): return 30; break;
        case(7): return 31; break;
        case(8): return 31; break;
        case(9): return 30; break;
        case(10): return 31; break;
        case(11): return 30; break;
        case(12): return 31; break;

    }

    return 0;

}
bool isLeapYear(int year){
    if(year%4 == 0){
        if(year%100== 0){
            if(year%400== 0)
                return true;
            else
                return false;
        }
        return true;
    }
    else{
        return false;
    }
}


Date::Date(){
    day = 1;
    month = JANUARY;
    year = 1900;
}
Date::Date(int dayc, Month monthc, int yearc){
    day = dayc;
    month = monthc;
    year = yearc;
}
Date::Date(Month monthc, int dayc, int yearc){
    day = dayc;
    month = monthc;
    year = yearc;
}

int Date::getDay(){
    return day;
}

Month Date::getMonth(){
    return month;
}

int Date::getYear(){
    return year;
}

int Date::getDayInYear(){
    int count = 0;
    for(Month i = JANUARY;i<month;i++){
        count += daysInMonth(i,year);
    }
    count = day + count;

    return count;
}


string abbr(Month month){
    switch (month) {
        case(1): return "Jan"; break;
        case(2): return "Feb"; break;
        case(3): return "Mar"; break;
        case(4): return "Apr"; break;
        case(5): return "May"; break;
        case(6): return "Jun"; break;
        case(7): return "Jul"; break;
        case(8): return "Aug"; break;
        case(9): return "Sep"; break;
        case(10): return "Oct"; break;
        case(11): return "Nov"; break;
        case(12): return "Dec"; break;
    }
    return "";
}

string Date::toString() {
   string ab = abbr(month);
   return to_string(day) + "-" + ab + "-" + to_string(year);
}

Month operator++(Month & month, int ){          //Design a loop for December to January
    if(month!=12){
        month = static_cast<Month>(month+1);
        return month;
    }
    else{
        month = static_cast<Month>(1);
        return month;
    }
}
Month operator++(Month & month ){          //Design a loop for December to January
    if(month!=12){
        month = static_cast<Month>(month+1);
        return month;
    }
    else{
        month = static_cast<Month>(1);
        return month;
    }
}

Month operator--(Month & month, int){



    if(month!=1){
        Month temp = month;
        month = static_cast<Month>(month-1);
        return temp;
    }
    else{
        Month temp = month;
        month = static_cast<Month>(12);
        return temp;
    }
}
Month operator--(Month & month){
    if(month!=1){
        month = static_cast<Month>(month-1);
        return month;
    }
    else{
        month = static_cast<Month>(12);
        return month;
    }
}


ostream & operator<<(ostream & os, Date date) {
   return os << date.toString();
}

bool operator<(Date d1, Date d2){
    if(d1.getYear() > d2.getYear())
        return false;
    else if (d2.getYear() > d1.getYear())
        return true;
    else{
        if(d1.getDayInYear()<d2.getDayInYear())
            return true;
        else
            return false;
    }
}

bool operator>(Date d1, Date d2){
    if(d1.getYear() > d2.getYear())
        return true;
    else if(d1.getYear() < d2.getYear())
        return false;
    else{
        if(d1.getDayInYear()>d2.getDayInYear())
            return true;
        else
            return false;
    }
}

bool operator<=(Date d1, Date d2){
    return !(d1>d2);
}

bool operator>=(Date d1, Date d2){
    return !(d1<d2);
}

bool operator==(Date d1, Date d2){
    if(d1.getDay() == d2.getDay() && d1.getYear() == d2.getYear() && d1.getMonth() == d2.getMonth())
        return true;
    else
        return false;
}

bool operator!=(Date d1, Date d2){
    return !(d1==d2);
}

Date operator+(Date date, int delta){
    Month mm = date.getMonth();
    int dd = date.getDay();
    int yy = date.getYear();
    int count = delta;
    if(daysInMonth(mm,yy) - dd >= delta){
        Date newdate(delta+dd,date.getMonth(),date.getYear());
        return newdate;
    }
    else{
        count = delta-(daysInMonth(mm,yy) - dd);
        if(mm == DECEMBER)
            yy++;
        mm++;
        while(count-daysInMonth(mm,yy)>0){
            count -= daysInMonth(mm,yy);
            mm++;
            if(mm== DECEMBER){
                yy++;
            }
        }
        Date newdate(count,mm,yy);
        return newdate;
    }
}

Date operator-(Date date, int delta){
    Month mm = date.getMonth();
    int dd = date.getDay();
    int yy = date.getYear();
    int count = delta;
    if(dd-delta>0){
        Date newdate(dd-delta,mm,yy);
        return newdate;
    }
    else{
        int count = delta-dd;
        if(mm == JANUARY)
            yy--;
        mm--;
        while(count-daysInMonth(mm,yy)> 0){
            count -=daysInMonth(mm,yy);
            mm--;
            if(mm == JANUARY)
                yy--;
        }
        Date newdate(daysInMonth(mm,yy)-count,mm,yy);
        return newdate ;
    }
}

Date operator++(Date & date){
    return date = (date+1) ;
}
Date operator++(Date & date, int){
    Date temp = date;
    date = date + 1;
    return temp ;
}
Date operator--(Date & date){
    return date = (date-1);
}
Date operator--(Date & date, int){
    Date temp = date;
    date = date - 1;
    return temp ;

}
Date & operator+=(Date & date, int delta){
    return date = date+delta;
}
Date & operator-=(Date & date, int delta){
        return date = date-delta;
}
int operator-(Date d1, Date d2){
    Date big_d, small_d;
    int diff_day;
    if(d1>d2){
        big_d = d1;small_d = d2;
    }
    else if (d1<d2){
        big_d = d2;small_d = d1;
    }
    else
        return 0;

    int big_day_sum = big_d.getDayInYear();
    int small_day_sum = small_d.getDayInYear();
    int count_year = big_d.getYear()-1;
    while(count_year-small_d.getYear()>=0){
        if(isLeapYear(count_year))
            big_day_sum+=366;
        else
            big_day_sum+=365;
        count_year-=1;
    }
    diff_day =   big_day_sum-small_day_sum;
    if(d1>d2){
        return diff_day;
    }
    else{
        return -diff_day;
    }
}
