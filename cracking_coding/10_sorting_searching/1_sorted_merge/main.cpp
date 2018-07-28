#include <iostream>

using namespace std;

void sorted_merge(int *a, int *b){
  
}

int main(){
  int a[10];
  int b[5];
  for(int i = 0; i < 5; i++){
    a[i] = i;
    b[i] = i;
  }
  sorted_merge(a, b);
  for(int i = 0; i < 10; i++){
    cout << a[i] << endl;
  }

  return 0;
}
