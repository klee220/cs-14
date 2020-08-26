#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <stdexcept>

using namespace std;

template<typename T>
void selection_sort(vector<T> &vals);

template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index);

template<typename T>
T getElement(vector<T> vals, int index);

//given code: creates a vector of characters with random size
vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++){
        vals.push_back(c);
        c++;
    }
    return vals;
}

int main(){
  //Part B
  try{
    srand(time(0));
    vector<char> vals = createVector();
    char curChar;
    int index;
    int numOfRuns = 10;
    int size = vals.size();
// ta said i should put the try block here!
    while(--numOfRuns >= 0){
      cout << "Enter a number: " << endl;
      cin >> index;
      if( size - 1 > index  || index < 0){
        throw out_of_range("std::outofrange");
      }
      curChar = getElement(vals,index);
      cout << "Element located at " << index << ": is " << curChar << endl;
    }
  }
  //if index is out of range in calling getElement function, output error message
  catch(const std::out_of_range& excpt){
      cout << "out of range exception occured" << endl;
  }
  return 0;
}

//passes in an index of type T and returns the index of the min value
template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index){
    unsigned int minIdex = index;
    for( unsigned int i = index; i < vals.size() ; i++){
        if( vals.at(i) <  vals.at(minIdex) ){
            minIdex = i;
        }
    }
    return minIdex;
}

//passes in a vector of type T and sorts them using the selection sort method
template<typename T>
void selection_sort(vector<T> &vals){
    for(unsigned int i = 0; i < vals.size(); ++i){
        int minIndex = min_index(vals, i);
        T moving_element = vals.at(i);
        vals.at(i) = vals.at(minIndex);
        vals.at(minIndex) = moving_element;
    }
}

//returns the element located at the index of the vals
template<typename T>
T getElement(vector<T> vals, int index){
    return vals.at(index);
}