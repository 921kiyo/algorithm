#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int partition(int* array, const int left, const int right){
  const int mid = left + (right - left) /2 ;
  // 1. Find a pivot value;
  const int pivot = array[mid];
  // Move the mid point value to the front
  // Swap the value to the front of the sequence,
  swap(array[mid], array[left]);
  int i = left + 1;
  int j = right;

  while(i <= j){
    // Move all values less than or equal to the pivot value to the left
    while(i <= j && array[i] <= pivot){
      i++;
    }
    // Move all values larger than the pivot to the right
    while(i <= j && array[j] > pivot){
      j--;
    }

    if(i < j){
      swap(array[i], array[j]);
    }
  }

  // Insert the pivot value at the right place.
  swap(array[i - 1], array[left]);
  return i - 1;
}

void quicksort(int* array, const int left, const int right, const int size){
  if(left >= right){
    return;
  }
  int part = partition(array, left, right);

  // Part is now at the right place, so you never have to include this pivot value in
  // sorting again.
  if(left < part - 1){
    quicksort(array, left, part - 1, size);
  }
  if(part + 1 < right){
    quicksort(array, part + 1, right, size);
  }
}

int main(){
  int array[8] = {110, 5, 10, 3, 22, 100, 1, 23};
  int sz = sizeof(array)/sizeof(array[0]);
  quicksort(array, 0, sz -1 , sz);
  for(int i = 0; i < sz; i++){
    cout << array[i] << endl;
  }
  return 0;
}
