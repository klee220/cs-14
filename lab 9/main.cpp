#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;


const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000; //clock per milliseconds
const int NUMBERS_SIZE = 50000;


//partitions into low and high parts
int Partition_midpoint(int numbers[], int i, int k) {
  int low = i;
  int high = k;
  int pivot = 0;
  int mid = 0;
  bool done = false;

  mid = (i + k) / 2;
  pivot = numbers[mid];

  while (!done) {
    while (numbers[low] < pivot) {
      ++low;
    }
    while (pivot < numbers[high]) {
      --high;
    }
    if (low >= high) {
      done = true;
    }
    else {
      swap(numbers[low], numbers[high]);
      ++low;
      --high;
    }
  }
  return high;
}

//partitions using a median
int Partition_median(int numbers[], int i, int k) {
  int low = 0;
  int high = 0;
  int pivot = 0;
  int m = 0;
  int mid = 0;
  bool done = false;
  mid = i + (k - i) / 2;

  if ((numbers[mid] <= numbers[k] && numbers[mid] >= numbers[i]) || (numbers[mid] <= numbers[i] && numbers[mid] >= numbers[k])) {
    m = mid;
  }
  else if ((numbers[i] <= numbers[mid] && numbers[i] >= numbers[k]) || (numbers[i] >= numbers[mid] && numbers[i] <= numbers[k])) {
    m = i;
  }
  else if ((numbers[k] <= numbers[i] && numbers[k] >= numbers[mid]) || (numbers[k] >= numbers[i] && numbers[k] <= numbers[mid])) {   
    m = k;
  }
  low = i;
  high = k;
  pivot = numbers[m];
  while (!done) {
    while (numbers[low] < pivot) {
      ++low;
    }    
    while (pivot < numbers[high]) {
      --high;
    }
    //no more elements remain to be sorted
    if (low >= high) {
      done = true;
    }
    else {
      swap(numbers[low], numbers[high]);
      ++low;
      --high;
    }
  }
  return high;
}

//this function sorts the given array in the range from i to k using quicksort method. In this function, pivot is the mid element (numbers[(i+k)/2]).
void Quicksort_midpoint(int numbers[], int i, int k) {
  int j = 0;

  // base case; no more elements to sort
  if (i >= k) {
    return;
  }
  
  //j is the last element in the low partition
  j = Partition_midpoint(numbers, i, k);
  
  //recursively sort low partition and high partition
  Quicksort_midpoint(numbers, i, j);
  Quicksort_midpoint(numbers, j + 1, k);
  
  return;
}

//this function utilizes different pivot selection technique in quicksort algorithm. The pivot is the m of the following three values: leftmost (numbers[i]), mid (numbers[(i+k)/2]) and rightmost (numbers[k]). You should modify the partition function given in section 21.5 to select the pivot using m-of-three technique.
void Quicksort_medianOfThree(int numbers[], int i, int k){
  int j = 0;
  
  //base case; no more elements to sort
  if (i >= k) {
    return;
  }
  
  //j is last element of low partition
  j = Partition_median(numbers, i, k);
  
  // recursively sort low partition and high partition
  Quicksort_medianOfThree(numbers, i, j);
  Quicksort_medianOfThree(numbers, j + 1, k);
  
  return;
}

//this function sorts the given array using InsertionSort method
void InsertionSort(int numbers[], int numbersSize){    
  int i = 0;
  int j = 0;
  
  for (i = 1; i < numbersSize; ++i) {
    j = i;

    // insert i into correct position
    while (j > 0 && numbers[j] < numbers[j - 1]) {
      swap(numbers[j], numbers[j - 1]);
      --j;
    }
  }
  return;
}

int genRandInt(int low, int high) {
  return low + rand() % (high - low + 1);
}

void fillArrays(int arr1[], int arr2[],int arr3[]){
  for(int i = 0; i < NUMBERS_SIZE; ++i){
    arr1[i] = genRandInt(0,NUMBERS_SIZE);
    arr2[i] = arr1[i];
    arr3[i] = arr1[i];
  }
}

int main(){
  srand(time(0));
  int elapsedTime = 0;
  int arr1[NUMBERS_SIZE];
  int arr2[NUMBERS_SIZE];
  int arr3[NUMBERS_SIZE];

  fillArrays(arr1, arr2, arr3);

  cout << "Quicksort midpoint unsorted" << endl;
  clock_t Start = clock();
  Quicksort_midpoint(arr1, 0, NUMBERS_SIZE - 1);
  clock_t End = clock();
  elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
  cout << "Elapsed time: " << elapsedTime << endl;

  cout << "Quicksort midpoint sorted" << endl;
  Start = clock();
  Quicksort_midpoint(arr1, 0, NUMBERS_SIZE - 1);
  End = clock();
  elapsedTime = (End - Start)/CLOCKS_PER_MS;
  cout << "Elapsed time: " << elapsedTime << endl;

  cout << "Quicksort median of three unsorted" << endl;
  Start = clock();
  Quicksort_medianOfThree(arr2, 0, NUMBERS_SIZE - 1);
  End = clock();
  elapsedTime = (End - Start)/CLOCKS_PER_MS;
  cout << "Elapsed time: " << elapsedTime << endl;

  cout << "Quicksort median of three sorted" << endl;
  Start = clock();
  Quicksort_medianOfThree(arr2, 0, NUMBERS_SIZE - 1);
  End = clock();
  elapsedTime = (End - Start)/CLOCKS_PER_MS;
  cout << "Elapsed time: " << elapsedTime << endl;

  cout << "insertion sort unsorted" << endl;
  Start = clock();
  InsertionSort(arr3, NUMBERS_SIZE - 1);
  End = clock();
  elapsedTime = (End - Start)/CLOCKS_PER_MS;
  cout << "Elapsed time: " << elapsedTime << endl;

  cout << "insertion sort sorted" << endl;
  Start = clock();
  InsertionSort(arr3, NUMBERS_SIZE - 1);
  End = clock();
  elapsedTime = (End - Start)/CLOCKS_PER_MS;
  cout << "Elapsed time: " << elapsedTime << endl;

  return 0;
}
