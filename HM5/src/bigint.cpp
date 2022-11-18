/*
 * File: bigint.cpp
 * ----------------
 * This file implements the bigint.h interface.
 */

#include <cctype>
#include <string>
#include "bigint.h"
#include "error.h"
using namespace std;

/*
 * Implementation notes: BigInt constructor
 * ----------------------------------------
 * The code for this constructor offers a minimal implementation
 * that matches what we would expect on an exam.  In a more
 * sophisticated implementation, it would make sense to include
 * a test to avoid storing leading zeros in the linked list.  In
 * this implementation, calling BigInt("00042") creates a
 * BigInt with a different internal representation than
 * BigInt("42"), which is probably a bad idea.
 */

BigInt :: BigInt(string str){
    int last_num = str[str.size()-1]-'0';
    Cell *cp = new Cell;
    cp->leadingDigits = NULL;
    cp->finalDigit = last_num;
    start = cp;
    Cell *pt = cp;

    for(int i = str.size()-2;i >= 0; i--){
        int num = str[i]-'0';
        Cell *cp = new Cell;
        cp->finalDigit = num;
        pt->leadingDigits = cp;
        pt = cp;

        if (i==0){
            cp->leadingDigits = NULL;
        }
    }
}


/*
 * Implementation notes: BigInt destructor
 * ---------------------------------------
 * The code for the destructor is similar to that of the other
 * classes that contain a linked list.  You need to store the
 * pointer to the next cell temporarily so that you still have
 * it after you delete the current cell.
 */

BigInt :: ~BigInt(){
    Cell *pt = start;

    while(pt != NULL){
        Cell *next = pt->leadingDigits;
        delete pt;
        pt = next;
    }
}


/*
 * Implementation notes: toString
 * ------------------------------
 * This method could also be written as a wrapper method that
 * calls a recursive function that creates the reversed string
 * one character at a time.
 */

string BigInt :: toString() const{

    string result = "";
    Cell *pt = start;
    while(pt!= NULL){
        result = std::to_string(pt->finalDigit) + result;
        pt = pt->leadingDigits;
    }
    return result;
}

BigInt BigInt::operator+(const BigInt & b2 ) const{

    //find out the size of the two bigint
    int size1 = (this->toString()).size();
    int size2 = b2.toString().size();

    string result = "";
    int carry = 0;
    Cell *pt1 = this->start;
    Cell *pt2 = b2.start;


    while(pt1 != NULL && pt2 != NULL ){
        int sum = (addWithCarry(pt1,pt2,carry)->finalDigit)%10;
        carry = (finalDigit(pt1)+finalDigit(pt2)+carry)/10;

        result = std::to_string(sum) + result;
        pt1 = pt1->leadingDigits;pt2 = pt2->leadingDigits;
    }


    //if they are equal length and with a extra carry
    if(size1 == size2 && carry == 1){
        result = "1" + result;
        return BigInt(result);
    }
    while(pt1!=NULL || pt2!= NULL){
        if(carry == 1){
            int remain;
            if(size1 > size2){
                remain = pt1->finalDigit;
                pt1= pt1->leadingDigits;
            }
            else{
                remain = pt2->finalDigit;
                pt2 = pt2->leadingDigits;
            }
            int newBit = (remain + carry) % 10;
            carry = (remain + carry) / 10;
            result = std::to_string(newBit) + result;

            //if the first digit and the carry generates a new carry
            if(pt1==NULL && pt2== NULL && carry == 1){
                result = std::to_string(carry) + result;
                break;
            }
        }
        else{
            if(size1>size2){
                result = std::to_string(pt1->finalDigit)+result;
                pt1 = pt1->leadingDigits;
            }
            else if (size1 < size2){
                result = std::to_string(pt2->finalDigit)+result;
                pt2 = pt2->leadingDigits;
            }
        }
    }

    //store digits in bits1 and bits2
    return BigInt(result);
}




BigInt BigInt ::operator*(const BigInt &b2) const{
    Cell *mulstart = mulStep(this->start, b2.start);
    BigInt * resultBigInt = new BigInt(NULL);
    resultBigInt->start = mulstart;
    return * resultBigInt;

};




