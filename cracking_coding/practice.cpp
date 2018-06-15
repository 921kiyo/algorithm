#include <iostream>

using namespace std;

const int MAX = 100;

class Stack{
  int index;
  int stack[MAX];
public:
  Stack(){
    index = -1;
  }
  bool push(int x){
    if(index > MAX){
      cout << "Stack overflow" << endl;
      return false;
    }else{
      stack[++index] = x;
      return true;
    }
  }
  int pop(){
    if(index < 0){
      cout << "Stack underflow" << endl;
      return -1;
    }else{
      int x = stack[index--];
      return x;
    }
  }
};

int main(){
  Stack stack;
  stack.push(10);
  stack.push(20);
  stack.push(30);
  cout << stack.pop() << endl;
  cout << stack.pop() << endl;
  cout << stack.pop() << endl;
  cout << stack.pop() << endl;
  return 0;
}
