#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

bool is_perm(string str1, string str2){
  int len1 = str1.length();
  int len2 = str2.length();

  if(len1 != len2){
    return false;
  }

  // O(N logN) version
  // sort(str1.begin(), str1.end());
  // sort(str2.begin(), str2.end());
  // return str1 == str2;

  // Assume extended ASCII (128 is normal ASCII)
  int char_set[256] = {0};

  for(int i = 0; i < len1; i++){
    int val = str1[i];
    char_set[val] ++;
  }

  for(int i = 0; i < len2; i++){
    int val = str2[i];
    if(char_set[val] <= 0){
      return false;
    }
    char_set[val] --;
  }

  return true;
}


int main(){
  cout << is_perm("hello", "llohe") << endl;
  cout << is_perm("hellao", "llohee") << endl;
  return 0;
}
