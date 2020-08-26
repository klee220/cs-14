#include "Heap.h"
#include <iostream>

using std::cout;
using std::endl;

// Initializes an empty heap
Heap::Heap(){
  numItems = 0;
}

// Inserts a PrintJob to the heap without violating max-heap properties
void Heap::enqueue(PrintJob* cur) {
  if (numItems < MAX_HEAP_SIZE) {
    if (empty()) {
      arr[numItems] = cur;
      ++numItems;
    }
    else {
      int i = numItems;
      while (i > 0 && (arr[(i - 1) / 2]->getPriority() < cur->getPriority())) {
        arr[i] = arr[(i - 1) / 2];
        i = (i - 1) / 2;
      }
      arr[i] = cur;
      ++numItems;
    }
  }
}

//Removes the node with highest priority from the heap. 
//Follow the algorithm on priority-queue slides. 
void Heap::dequeue() {
  //if item does not violate heap property
	if ((numItems > 2 && arr[1]->getPriority() < arr[numItems - 1]->getPriority()) && (arr[2]->getPriority() < arr[numItems - 1]->getPriority())) {
		arr[0] = arr[numItems - 1]; 
		--numItems;
	}
  //if heap prop is violated
	else { 
		trickleDown(0);
		--numItems;
	}
}

//Returns the node with highest priority.
PrintJob* Heap::highest(){
  return numItems == 0 ? nullptr : arr[0];
}

//Prints the PrintJob with highest priority in the following format:
//Priority: priority, Job Number: jobNum, Number of Pages: numPages
//New line at end
void Heap::print ( ){
  if (!empty()){
  cout << "Priority: " << arr[0]->getPriority()
    << ", Job Number: " << arr[0]->getJobNumber() 
    << ", Number of Pages: " << arr[0]->getPages() 
    << endl; 
  }
}

/*Called by dequeue function to move the new root down the heap to the appropriate location.*/
void Heap::trickleDown(int i){
  PrintJob* leftChild = arr[i * 2 + 1];
  PrintJob* rightChild = arr[i * 2 + 2];
  // if 2 children
  if (((i * 2 + 1) < numItems) && ((i * 2 + 2) < numItems)) {
    //if left child is greater, assign passed in index to left and trickle
    if (leftChild->getPriority() > rightChild->getPriority()) {
      arr[i] = leftChild;
      trickleDown(i * 2 + 1);
      }
    //if right child is greater, assign passed in index to right and trickle
    else { 
      arr[i] = rightChild;
      trickleDown(i * 2 + 2);
    }
  }
  //if 1 child
  else if ((i * 2 + 1) < numItems) { 
    arr[i] = leftChild;
  }
  //if no children
  else {
    return;
  }
}