/*
 * File: reversequeue.cpp
 * ----------------------
 * This file implements the reversequeue.h interface
 */


#include "reversequeue.h"
#include <iostream>
#include "stack.h"
using namespace std;
// TODO

void listQueue(Queue<std::string> & queue){
    string str = queue.toString();
    str = str.substr(1,-2);

//    while(str.find(",") != -1){
//        str.replace(str.find(","), 1, )
//    }
    cout << "The queue contains: ";
    cout << str<<endl;
}
void reverseQueue(Queue<std::string> & queue){
    Stack<std::string> stk;
    while(!queue.isEmpty()){
        string str = queue.dequeue();
        stk.push(str);
    }
    while(!stk.isEmpty()){
        string str = stk.pop();
        queue.enqueue(str);
    }
}
