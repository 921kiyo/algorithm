#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> aVector, int size, int low, int middle, int high){
  int temp[size];
  for(int i = low; i <= high; i++){
    temp[i] = aVector[i];
  }

  int i = low;
  int j = middle+1;
  int k = low;

  while(i <= middle && j <= high){
    if(temp[i] <= temp[j]){
      aVector[k] = temp[i];
      ++i;
    }
    else{
      aVector[k] = temp[j];
      ++j;
    }
    ++k;
  }
  while(i <= middle){
    aVector[]
  }

}

void mergeSort(vector<int> aVector, int size, int low, int high){
  if(low < high){
    int middle = (low + high)/2;
    mergeSort(aVector, size, low, middle);
    mergeSort(aVector, size, middle+1, high);
    merge(aVector, size, low, middle, high);
  }

}



int vectorOfInts(vector<int>& vec){
  vector<int> three;

  // Sort vec


  int total = 1;
  int counter = 0;
  int vector_size = vec.size();

}



int main(){
  vector<int> vec = {-10, -10, 3};
  int answer = vectorOfInts(vec);
  cout << answer << endl;
}
