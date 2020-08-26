#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(string d) {
	data = d;
  count = 1;
	left = 0;
	right = 0;
	parent = 0;
}