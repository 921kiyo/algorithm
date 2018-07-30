#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class NodeWithMin{
int data;
NodeWithMin *next;
NodeWithMin *minimum;

public:
  friend class StackMin;
  NodeWithMin(int data_, NodeWithMin *next_){
    data = data_;
    next = next_;
    minimum = nullptr;
  }
};

class StackMin{
private:
  int stackSize;
  NodeWithMin * head;
  vector<int>stack;
public:
  StackMin():stackSize(0), head(nullptr){}

  void push(int item){
    if(isEmpty()){
      head = new NodeWithMin(item, nullptr);
      head->minimum = head;
    }
    else if(item <= head->minimum->data){
      head = new NodeWithMin(item, head);
      head->minimum = head;
    }else{
      head = new NodeWithMin(item, head);
      head->minimum = head->next->minimum;
    }
    stackSize++;
  }

  void pop(){
    if(stackSize == 0 || head == nullptr){
      cout << "Stack is empty..." << endl;
      return;
    }
    NodeWithMin *discard = head;
    head = head->next;
    delete discard;
    stackSize--;
  }

  int top() const {
    if(stackSize == 0 || head == nullptr){
      cout << "Stack is empty " << endl;
      exit(1);
    }
    return head->data;
  }

  int isEmpty() const{
    return (stackSize == 0 || head == nullptr);
  }

  int getMin() const {
    if(stackSize == 0 || head == nullptr){
      cout << "Stack is empty " << endl;
      exit(1);
    }
    return (head->minimum->data);
  }

};

int main(){
  StackMin stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  cout << stack.getMin() << endl;
  return 0;
}
