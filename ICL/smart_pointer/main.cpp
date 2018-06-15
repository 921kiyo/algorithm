#include <iostream>

using namespace std;


template <class T>
class SmartPtr{
private:
  int counter;
  T *ptr;

public:
  SmartPtr(T* obj){
    counter = 1;
    ptr = obj
  }



  ~SmartPtr(){
    counter --;
    if(counter <= 0){
      delete ptr;
    }
  }
};

int main(){
  return 0;
}
