#include <iostream>
#include <vector>

using namespace std;

class Stack{
private:
  int* stack;
  int top;
  int capacity;
public:
  Stack(int cap): top(0), capacity(cap){
    stack = new int[cap];
  }
  bool push(int data){

    if(isFull()){
      return false;
    }else{
      stack[++top] = data;
      return true;
    }
  }
  int pop(){
    if(isEmpty()){
      return -1;
    }else{
      int result = stack[top--];
      return result;
    }
  }

  bool isEmpty(){
    return (top == 0);
  }
  bool isFull(){
    return (capacity == top);
  }

  void print(){
    for(int i = 0; i < top; i++){
      cout << stack[i] << endl;
    }
  }
};

class SetOfStacks{
private:
vector<Stack*> stacks;
int capacity;
int top;

public:
  SetOfStacks(int cap): capacity(cap), top(0){
    stacks.push_back(new Stack(capacity));
  }

  bool push(int data){
    if(isFull(stacks[top])){
      stacks.push_back(new Stack(capacity));
      top++;
      stacks[top]->push(data);
    }else{
      stacks[top]->push(data);
    }
    return true;
  }

  int pop(){
    if(isEmpty()){
      return -1;
    }else if(stacks[top]->isEmpty()){
      Stack* discard = stacks[top];
      delete discard;
      top--;
      return stacks[top]->pop();
    }else{
      stacks[top]->print();
      return stacks[top]->pop();
    }
  }

  bool isFull(Stack* stack){
    return stack->isFull();
  }

  bool isEmpty(){
    return (top == 0 && stacks[top]->isEmpty());
  }
};

int main(){
  SetOfStacks stackSet(3);
  stackSet.push(1);
  stackSet.push(2);
  stackSet.push(3);
  stackSet.push(4);
  cout << stackSet.pop() << endl;
  return 0;
}
