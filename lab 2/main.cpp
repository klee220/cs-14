#include <iostream>
using namespace std;

#include "IntList.h"

int main() {
  IntList l;
  cout << "Testing push_back and push_front" << endl;
  l.push_back(5);
  l.push_back(62);
  l.push_back(30);
  l.push_back(-6);
  l.push_back(34);
  l.push_front(22);
  l.push_back(8);
  cout << "List:" << endl;
  cout << l << endl;
  cout << "Testing print list in reverse:" << endl;
  l.printReverse();
  cout << endl;
  cout << "Testing pop_front and pop_back" << endl;
  l.pop_back();
  l.pop_front();
  cout << "List: " << endl;
  cout << l << endl;

  return 0;
}