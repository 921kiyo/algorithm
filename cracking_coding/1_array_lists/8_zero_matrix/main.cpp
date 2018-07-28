#include <iostream>

using namespace std;

const int M = 5;
const int N = 4;

bool zero_matrix(int matrix[][N]){
  bool rows[M]{false};
  bool columns[N]{false};
  for(int m = 0; m < M; m++){
    for(int n=0; n < N; n++){
      if (matrix[m][n] == 0){
        rows[m] = true;
        columns[n] = true;
      }
    }
  }
  for(int m = 0; m < M; m++){
    if(rows[m] == true){
      for(int n=0; n< N; n++){
        matrix[m][n] = 0;
      }
    }
    for(int n=0; n < N; n++){
      if(columns[n] == true){
        matrix[m][n] = 0;
      }
    }
  }
  return true;
}

int main(){
  int matrix[M][N];
  for(int m = 0; m < M; m++){
    for(int n=0; n < N; n++){
      matrix[m][n] = 1;
    }
  }
  matrix[0][0] = 0;
  zero_matrix(matrix);
  for(int m = 0; m < M; m++){
    for(int n=0; n < N; n++){
      cout << matrix[m][n];
    }
    cout << endl;
  }
  return 0;
}
