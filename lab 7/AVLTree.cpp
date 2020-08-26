#include <string>
#include<fstream>
using namespace std;

#include "AVLTree.h"
#include "Node.h"

AVLTree::AVLTree() {
  root = 0;
}

//Insert an item to the binary search tree and perform rotation if necessary.
void AVLTree::insert(const string &s) {
  Node* unbalanced = 0;

  if (root == 0) { //if no root exists
    root = new Node(s);
    return;
  }
  else {
    Node* cur = root;

    while (cur != 0) {
      if (s == cur->data) { //if item already exists
        return;
      }
      if (s < cur->data) {
        if (cur->left == 0) { //if left is null
          cur->left = new Node(s); //insert left
          cur->left->parent = cur;
          unbalanced = 0;
          unbalanced = findUnbalancedNode(cur->left); //return closest unbalanced node
          if (unbalanced != 0) {
            rotate(unbalanced);
          }
          return;
          }
        else {
          cur = cur->left;
        }
      }
      else { //if s is greater than cur->data
        if (cur->right == 0) { //if right is null
          cur->right = new Node(s); //insert right
          cur->right->parent = cur;
          unbalanced = 0;
          unbalanced = findUnbalancedNode(cur->right); //return closest unbalanced node
          if (unbalanced != 0) {
            rotate(unbalanced);
          }
          return;
        }
        else {
          cur = cur->right;
        }
      }
    }
  }
}

//Return the balance factor of a given node.
int AVLTree::balanceFactor(Node *cur) {
  return height(cur->left) - height(cur->right);
}

//Traverse and print the tree in inorder notation. Print the string followed by its balance factor in parentheses followed by a , and one space.
void AVLTree::printBalanceFactors() {
  printBalanceFactors(root); 
  cout << endl;
} 

void AVLTree::printBalanceFactors(Node *cur) {
  if(cur != 0) {
    printBalanceFactors(cur->left); 
    cout << cur->data << '(' << balanceFactor(cur) << "), "; 
    printBalanceFactors(cur->right); 
  }
}

// Find and return the closest unbalanced node (with balance factor of 2 or -2) to the inserted node.
Node* AVLTree::findUnbalancedNode(Node* a) {
	Node* cur = a;
	while (cur != 0) {
		if (balanceFactor(cur) >= 2 || balanceFactor(cur) <= -2) {
			return cur;
		}
		else {
			cur = cur->parent;
		}
	}
	return 0;
}

//Implement four possible imbalance cases and update the parent of the given node.
void AVLTree::rotate(Node *cur) { 
  if(balanceFactor(cur) == 2) {
    if(balanceFactor(cur->left) == -1) {
      rotateLeft(cur->left);
    } 
    rotateRight(cur);
  }
  else if(balanceFactor(cur) == -2) {
    if(balanceFactor(cur->right) == 1) { 
      rotateRight(cur->right); 
    } 
    rotateLeft(cur);
  }
}

//Rotate the subtree to left at the given node and returns the new subroot.
Node* AVLTree::rotateLeft (Node* cur) {
  Node* rootn = 0;

  rootn = cur->right;
  cur->right = rootn->left;

  if (cur != root) {
    if (cur->parent->left == cur) {
      cur->parent->left = rootn;
    }
    if (cur->parent->right == cur) {
      cur->parent->right = rootn;
    }
  }
  rootn->parent = cur->parent;
  cur->parent = rootn;
  rootn->left = cur;
  if (cur == root) {
    root = rootn;
  }
  return rootn;
}

//Rotate the subtree to right at the given node and returns the new subroot.
Node* AVLTree::rotateRight (Node* cur) {
  Node* rootn = 0;

  rootn = cur->left;
  cur->left = rootn->right;
  if (cur != root) {
    if (cur->parent->left == cur) {
      cur->parent->left = rootn;
    }

    if (cur->parent->right == cur) {
      cur->parent->right = rootn;
    }
  }
  rootn->parent = cur->parent;
  cur->parent = rootn;
  rootn->right = cur;
  if (cur == root) {
    root = rootn;
  }
  return rootn;
}

int AVLTree::height(Node* node) {
  int l = 0;
  int r = 0;
  int total = 0;

  if (node != 0) {
    l = height(node->left);
    r = height(node->right);
    int height = max(l, r);
    total = height + 1;
  }
  return total;
}

// Generate dotty file and visualize the tree using dotty program. Call this function before and after rotation.
void AVLTree::visualizeTree(const string &outputFilename){
  ofstream outFS(outputFilename.c_str());
  if(!outFS.is_open()){
    cout<<"Error"<<endl;
    return;
  }
  outFS<<"digraph G {"<<endl;
  visualizeTree(outFS,root);
  outFS<<"}";
  outFS.close();
  string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
  string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
  system(command.c_str());
}

void AVLTree::visualizeTree(ofstream & outFS, Node *n){
  if(n){
    if(n->left){
      visualizeTree(outFS,n->left);
      outFS<<n->data <<" -> " <<n->left->data<<";"<<endl;
    }

    if(n->right){
      visualizeTree(outFS,n->right);
      outFS<<n->data <<" -> " <<n->right->data<<";"<<endl;
    }
  }
}


