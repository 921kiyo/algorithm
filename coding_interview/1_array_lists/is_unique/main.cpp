#include <iostream>
#include <cstring>
#include <string>
using namespace std;

bool appear_before(char letter, int position, const char* word){
  for(int i = 0; i < position; i++){
    if(word[i] == word[position]){
      return true;
    }
  }
  return false;
}

bool is_unique(const char* word){
  int length = strlen(word);
  for(int i = length; i >= 0; i--){
    if(appear_before(word[i], i, word)){
        return false;
    }
  }
  return true;
}

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

void print(const char* word){
  if(is_unique(word)){
    cout << word << " is unique" << endl;
  }else{
    cout << word << " is NOT unique" << endl;
  }
}

int main(){
  print("hello");
  print("symbol");
  cout << is_unique2("symbol") << endl;

  return 0;
}
