#include <iostream>
#include <cstdlib>

using namespace std;

class NodeWithNum{
private:
  int data;
  NodeWithNum* next;
  NodeWithNum* minimum;
public:
  friend class MinStack;
  NodeWithNum(int data_, NodeWithNum* next_): data(data_), next(next_), minimum(nullptr){}
};

class MinStack{
private:
  int stackSize;
  NodeWithNum* head;
public:
  MinStack(): stackSize(0), head(nullptr){}

  void push(int data){
    if(isEmpty()){
      head = new NodeWithNum(data, nullptr);
      head->minimum = head;
    }else if(data <= head->minimum->data){
      head = new NodeWithNum(data, head);
      head->minimum = head;
    }else{
      head = new NodeWithNum(data, head);
      head->minimum = head->next->minimum;
    }
    stackSize++;
  }

  void pop(){
    if(isEmpty()){
      cout << "Stack is empty " << endl;
      exit(1);
    }else{
      NodeWithNum* discard = head;
      head = head->next;
      delete discard;
      stackSize--;
    }
  }

  bool isEmpty(){
    return (head == nullptr || stackSize == 0);
  }

  int getMin(){
    if(isEmpty()){
      cout << "Stack is empty " << endl;
      exit(1);
    }else{
      return head->minimum->data;
    }
  }
};

int main(){
  MinStack stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  cout << stack.getMin() << endl;
  return 0;
}
