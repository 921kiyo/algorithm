#include <iostream>
#include <string>

#include <string.h>

using namespace std;

int findWays(int m, int n, int x){
  // Create a table to store results of subproblems. One extra row and column are used for the number of dice as row index
  // and the sum is used for column index

  int table[n+1][x+1];
  memset(table, 0, sizeof(table));

  // table entry for only one dice
  for (int j = 1; j <= m && j <= x; j++){
    table[1][j] = 1;
  }

  // i the number is dice
  // j sum

  for (int i = 2; i <= n; i++){
    for(int j = 1; j <= x; j++){
      for (int k = 1; k <= m && k < j; k++){
        table[i][j] += table[i-1][j-k];
      }
    }
  }
  cout << "------------" << endl;
  for (int i = 0; i <= n; i++){
    for (int j = 0; j <= x; j++){
      cout << table[i][j] << " ";
    }
    cout << endl;
  }
  return table[n][x];
}

int main(){
  cout << findWays(4,2,1) << endl;
  cout << findWays(2,2,3) << endl;
  cout << findWays(6,3,8) << endl;

  return 0;
}
