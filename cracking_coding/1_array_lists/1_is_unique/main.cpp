#include <iostream>
#include <cstring>
#include <string>
using namespace std;

bool is_unique2(const string& str){
  if(str.length() > 256){
    return false;
  }

  bool ascii_set[256] = {false};

  for(int i = 0; i < str.length(); i++){
    int value = str[i];
    if(ascii_set[value]){
      return false;
    }
    ascii_set[value] = true;
  }

  return true;
}

int main(){
  cout << is_unique2("symbol") << endl;

  return 0;
}
