#include <iostream>
using namespace std;

#ifndef STACK_H
#define STACK_H

const int MAX_SIZE = 20;

template<typename T>
class stack {
  private:
    //An array with maximum size of 20
    T data[MAX_SIZE];
    //stores the current number of elements in the stack
    int size;

  public:
    //constructs an empty stack
    stack() {
      size = 0;
    }

    //inserts a new element (val) of type T (T could be integer or string) into the data
    //If the data array is full, this function should throw an overflow_error exception 
    void push(T val) {
      if (size == MAX_SIZE) {
        throw overflow_error("Called push on full stack.");
      }
      data[size] = val;
      ++size;
    }

    //removes the last element from data. If the data array is empty, this function should throw an outofrange exception
    void pop() {
      if (size > 0) {
        --size;
      }
      else {
        throw underflow_error("Called pop on empty stack.");
      }
    }

    //returns the top element of stack (last inserted element). If stack is empty, this function should throw an underflow_error exception
    T top() {
      T val;

      if (size > 0) {
        val = data[size - 1];
      }
      else {
        throw underflow_error("Called top on empty stack.");
      }
      return val;
    }

    //returns true if the stack is empty otherwise it returns false.
    bool empty() {
      if (size == 0) {
        return true;
      }
      return false;
    }
  };

#endif
