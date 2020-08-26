#include "IntList.h"

#include <iostream>
using namespace std;

//initializes empty list with dummy head and tail
IntList::IntList(){
  dummyHead = new IntNode(0);
  dummyTail = new IntNode(0);
  dummyHead->next = dummyTail; 
  dummyHead->prev = dummyTail;
  dummyTail->next = dummyHead;
  dummyTail->prev = dummyHead;
}

//deallocates all remaining IntNodes
IntList::~IntList(){
  while (!empty()){
    pop_front();
  }
}

//inserts a data value (within a new node) at front of list
void IntList::push_front(int value){
  IntNode* a = new IntNode(value);
  IntNode* temp = dummyHead->next;
  a->next = temp;
  a->prev = dummyHead;
  dummyHead->next = a;
  temp->prev = a;
}

void IntList::pop_front(){
  if (!empty()){
    IntNode* a = dummyHead->next;
    dummyHead->next = a->next;
    a->next->prev = dummyHead;
    delete a;
  }
}

void IntList::push_back(int value){
  IntNode* a = new IntNode(value);
  IntNode* temp = dummyTail->prev;
  a->prev = temp;
  a->next = dummyTail;
  temp->next = a;
  dummyTail->prev = a;
}

void IntList::pop_back(){
  if (!empty()){
    IntNode* a = dummyTail->prev;
    dummyTail->prev = a->prev;
    a->prev->next = dummyTail;
    delete a;
  }
}

bool IntList::empty() const{
  if (dummyHead->next == dummyTail){
    return true;
  }
  else {
    return false;
  }
}

ostream & operator<<(ostream &out, const IntList &rhs){
  IntNode* a = rhs.dummyHead->next;
  while (a != rhs.dummyTail){
    out << a->data;
    a = a->next;
    if (a != rhs.dummyTail){
      out << ' ';
    }
  }
  return out;
}

void IntList::printReverse() const{
  if(!empty()){
    IntNode* a = dummyTail->prev;
    while (a->prev != dummyHead){
      cout << a->data << " ";
      a = a->prev;
    }
    cout << a->data;
  }
}
