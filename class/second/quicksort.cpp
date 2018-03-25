#include <iostream>

using namespace std;

int partition(int array[], const int right, const int left){

}

void quicksort(int array[], const int left, const int right, const int size){
  if(left >= right){
    return;
  }

  int
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
