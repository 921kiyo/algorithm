#include <iostream>
#include <string>

using namespace std;

bool is_one_away(string str1, string str2){
  int table[256] = {0};
  for(int i = 0; str1.length() > i; i++){
    int index = str1[i];
    table[index] ++;
  }

  for(int i = 0; str2.length() > i; i++){
    int index = str2[i];
    table[index] --;
  }

  bool is_away = false;

  for(int i = 0; 256 > i; i++){
    if(table[i] != 0){
      if(is_away){
        return false;
      }
      is_away = true;
    }
  }
  return true;
}
int main(){
  cout << is_one_away("pale", "ple") << endl;
  cout << is_one_away("pale", "bake") << endl;
  cout << is_one_away("pale", "pale") << endl;
  return 0;
}
