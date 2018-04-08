#include <iostream>
#include <vector>

using namespace std;

// void func1(int array[]){
void func1(vector<int>& array){
  for(int i = 0; i < 5; i++){
    for(int j = i+1; j < 5; j++){
      int total = 0;
      for(int x = i; x < j; x++){
        total += array[x];
      }
      cout << total << " ";
      // arrayB[i][j] = total;
    }
    cout << endl;
  }
}

void func2(vector<int>& array){
  vector<vector<int>> arrayB(5, vector<int>(5));
  for(int i = 0; i < 5; i++){
    if(i==0){
      arrayB[0][0] = array[i];
    }else{
      arrayB[i-1][i] = array[i-1]+array[i];
    }
  }
  for(int k = 1; k<5-1; k++){
    for(int i = 0; i<5-k; i++){
      int j = i+k;
      cout << endl;
      // cout << "arrayB[i][j] " << i << " " << j << endl;
      // cout << "arrayB[i][j-1] " << arrayB[i][j-1] << endl;
      // cout << "array[j] " << array[j] << endl;
      arrayB[i][j] = arrayB[i][j-1] + array[j];
    }
  }
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      cout << arrayB[i][j] << " ";
    }
    cout << endl;
  }
}

void func1(int array[]){
  for(int i = 0; i < 5; i++){
    for(int j = i+1; j < 5; j++){
      int total = 0;
      for(int x = i; x < j; x++){
        total += array[x];
      }
      cout << total << " ";
    }
    cout << endl;
  }
}

int main(){
  // int array[5] = {1,2,3,4,5};
   vector<int> array = {1,2,3,4,5};
  func1  (array);
  func2(array);
  return 0;
}
