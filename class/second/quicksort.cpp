#include <iostream>

using namespace std;

int partition(int array[], int left, int right){

}

void quicksort(int array[], int left, int right, int size){
  if(left >= right){
    return;
  }
  int part = partition(array, left, right);

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
