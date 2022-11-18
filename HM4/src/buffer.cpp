/*
 * File: buffer.cpp (list version without dummy cell)
 * --------------------------------------------------
 * This file implements the EditorBuffer class using a linked
 * list to represent the buffer.
 */

#include <iostream>
#include "buffer.h"
using namespace std;

/*
 * This function initializes an empty editor buffer, represented as a doubly linked list.  In this implementation, the ends of
 * the linked list are joined to form a ring, with the dummy cell at both the beginning and the end.  This representation makes
 * it possible to implement the moveCursorToEnd method in constant time, and reduces the number of special cases in the code.
 */

EditorBuffer::EditorBuffer() {
   start = cursor = new Cell;
   start->next = start;
   start->prev = start;
}

/*
 * Implementation notes: cursor movement
 * -------------------------------------
 * In a doubly linked list, each of these operations runs in
 * constant time.
 */

EditorBuffer::~EditorBuffer() {
    Cell *temp = start;
    while(temp != NULL){
        Cell *next = temp->next;
        delete temp;
        temp = next;
    }
}


void EditorBuffer::moveCursorForward() {
    if (cursor->next != start) {
      cursor = cursor->next;
    }
    else{
        cout << "cursor at the right end" << endl;
    }
}
void EditorBuffer::moveCursorBackward(){
    cout << "moveCursorBackward" << endl;
    if (cursor != start){
        cursor = cursor->prev;
    }
    else
        cout << "cursor at the left end" << endl;
}
void EditorBuffer::moveCursorToStart(){
    cout << "moveCursorToStart" << endl;
    cursor = start;
}
void EditorBuffer::moveCursorToEnd(){
    cout << "moveCursorToEnd" << endl;
    cursor = start->prev;
}
void EditorBuffer::insertCharacter(char ch){
    cout << "insertCharacter " << ch << endl;
    Cell *insertCell = new Cell;
    insertCell->ch = ch;
    insertCell->next = cursor->next;
    insertCell->prev = cursor;
    cursor->next->prev = insertCell;
    cursor->next = insertCell;
    cursor = insertCell;

}

void EditorBuffer::deleteCharacter(){
    cout << "deleteCharacter" << endl;
    Cell *deleteCell = cursor->next;
    if(cursor != start && deleteCell == start){
        deleteCell = cursor;
        cursor->prev->next = cursor->next;
        cursor->next->prev = cursor->prev;
        delete cursor;
        cursor = cursor->prev;
    }
    else{
        cursor->next = deleteCell->next;
        deleteCell->next->prev = cursor;
        delete  deleteCell;
    }
//    cursor = cursor->next;
}

string EditorBuffer::getText() const{
    string text = "";

    if(start == NULL || start->next == NULL){
        cout << "Empty buffer!" <<endl;
        return text;
    }


    Cell *temp = new Cell;
    temp = start->next;
    while(temp != start){
        text.push_back(temp->ch);
        temp = temp->next;
    }
    return text;

}
int EditorBuffer::getCursor() const{
    Cell *temp = new Cell;
    temp = start;
    int index = 0;
    while(temp != cursor){
        index+=1;
        temp = temp->next;
    }
    return index;
}

