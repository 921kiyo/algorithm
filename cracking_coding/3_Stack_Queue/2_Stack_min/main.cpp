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
public:
  StackMin():stackSize(0), head(nullptr){}

  void push(int item){
    if(isEmpty()){
      // next is null
      head = new NodeWithMin(item, nullptr);
      // minimum is head since there is only one element
      head->minimum = head;
    }
    // If new item is smaller than minimum
    else if(item <= head->minimum->data){
      // next is previous minimum head
      head = new NodeWithMin(item, head);
      // this head is the minimum
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
