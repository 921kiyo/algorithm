#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

void merge(int* a, int low, int high, int mid){
  int i,j,k,temp[high-low+1];
  cout << "length " << temp[high-low+1] << endl;
  i=low;
  k=0;
  j=mid+1;

  // Merge two parts into temp[]
  while((i<=mid) && (j<=high)){
    if(a[i] < a[j]){
      temp[k] = a[i];
      k++;
      i++;
    }
    else{
      temp[k] = a[j];
      k++;
      j++;
    }
  }

  // 
}

void mergesort(){

}


int main(){
  int array[8] = {110, 5, 10, 3, 22, 100, 1, 23};
  int sz = sizeof(array)/sizeof(array[0]);
  mergesort(array, 0, sz -1 , sz);
  for(int i = 0; i < sz; i++){
    cout << array[i] << endl;
  }
  return 0;
}
