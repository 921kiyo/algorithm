#include <iostream>
#include <cstdlib>

using namespace std;

class MultiStack{
private:
  const int numOfStack = 3;
  int stackCapacity;
  int *stackArray;
  int *stackCapacityUsed;

  int indexOfTop(int stackNum) const{
    int startIndex = stackNum*stackCapacity;
    int capacity = stackCapacityUsed[stackNum];
    return (startIndex + capacity - 1);
  }

public:
  // MultiStack(int stackCapacity_)
  // {
  //   stackCapacity = stackCapacity_;
  //   stackArray = new int[numOfStack * stackCapacity_]();
  //   stackCapacityUsed = new int[numOfStack]();
  // }
  MultiStack(int stackCapacity_){
    stackCapacity = stackCapacity_;
    stackArray = new int[numOfStack*stackCapacity]();
    stackCapacityUsed = new int[numOfStack]();
    for(int i = 0; i < numOfStack; i++){
      cout << stackCapacityUsed[i] << endl;
    }
  }
  virtual ~MultiStack(){
    delete [] stackArray;
    delete [] stackCapacityUsed;
  }
  void push(int stackNum, int value){
    if(isFull(stackNum)){
      cout << "Stack " << stackNum << " is full." << endl;
    }else{
      stackCapacityUsed[stackNum]++;
      stackArray[indexOfTop(stackNum)] = value;
    }
  }

  int pop(int stackNum){
    if(isEmpty(stackNum)){
      cout << "Stack " << stackNum << " is empty." << endl;
      exit(1);
    }

    int topIndex = indexOfTop(stackNum);
    int result = stackArray[topIndex];
    stackArray[topIndex] = 0;
    stackCapacityUsed[stackNum]--;
    return result;
  }

  int top(int stackNum) const {
    if(isEmpty(stackNum)){
      cout << "Stack " << stackNum << " is empty." << endl;
      exit(1);
    }else{
      return stackArray[indexOfTop(stackNum)];
    }
  }

  bool isEmpty(int stackNum) const {
    return (stackCapacityUsed[stackNum] == 0);
  }

  bool isFull(int stackNum) const {
    return (stackCapacityUsed[stackNum] == stackCapacity);
  }
};

int main(){
  MultiStack multistack(10);
  multistack.push(1,1);

  return 0;
}
