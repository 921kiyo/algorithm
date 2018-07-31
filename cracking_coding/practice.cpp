#include <iostream>
#include <cstdlib>

using namespace std;

class MultiStack{
private:
  static const int numStack = 3;
  int stackCapacity;
  int* stackCapacityUsed;
  int* stackArray;
  
  int indexOfTop(int stackNum){
    int startIndex = stackNum*stackCapacity;
    int capacity = stackCapacityUsed[stackNum];
    return (startIndex+capacity-1);
  }

public:
  MultiStack(int capacity){
    stackCapacity = capacity;
    stackArray = new int[capacity*numStack]();
    stackCapacityUsed = new int[numStack]();
  }

  ~MultiStack(){
    delete [] stackArray;
    delete [] stackCapacityUsed;
  }

  void push(int stackNum, int data){
    if(isFull(stackNum)){
      cout << "Stack " << stackNum << " is full." << endl;
      exit(1);
    }else{
      stackCapacityUsed[stackNum]++;
      stackArray[indexOfTop(stackNum)] = data;
    }
  }

  int pop(int stackNum){
    if(isEmpty(stackNum)){
      cout << "Stack " << stackNum << " is empty." << endl;
      exit(1);
    }else{
      int data = stackArray[indexOfTop(stackNum)];
      stackArray[indexOfTop(stackNum)] = 0;
      stackCapacityUsed[stackNum]--;
      return data;
    }
  }

  bool isFull(int stackNum){
    return (stackCapacityUsed[stackNum] == stackCapacity);
  }

  bool isEmpty(int stackNum){
    return (stackCapacityUsed[stackNum] == 0);
  }

  int top(int stackNum) {
    if(isEmpty(stackNum)){
      cout << "Stack " << stackNum << " is empty." << endl;
      exit(1);
    }else{
      return stackArray[indexOfTop(stackNum)];
    }
  }
};

int main(){
  MultiStack stack(10);
  stack.push(1,1);
  return 0;
}