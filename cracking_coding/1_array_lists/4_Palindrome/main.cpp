#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


bool check_range(char c){
  return ('a' <= c && 'z' >= c);
}

bool is_permutation(string str){

  // Change everything to lowercase
  transform(str.begin(), str.end(), str.begin(), ::tolower);

  bool is_odd = false;
  int length = str.length();
  int table[256] = {0};

  for(int i = 0; length > i; i++){
    if(!check_range(str[i])){
      continue;
    }else{
      int index = str[i];
      table[index] ++;
    }
  }

  for(int i = 0; 256 > i; i++){

    if(table[i]%2 == 1){
      if(is_odd == false){
        is_odd = true;
      }
      else{
        return false;
      }
    }
  }

  return true;
}

int main(){
  cout << is_permutation("taco cat") << endl;
  cout << is_permutation("atco cta") << endl;
  cout << is_permutation("aabbccc") << endl;
  return 0;
}
