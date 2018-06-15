#include <iostream>

using namespace std;

const int MAX = 100;

class Queue{
  int queue[MAX];
  int front, rear;
public:
  Queue(){
    front = rear = -1;
  }
  bool isFull(){
    return (rear+1)%MAX == front ? true : false;
  }
  bool isEmpty(){
    return (front == -1 && rear == -1);
  }
  bool enqueue(int x){
    if(isFull()){
      cout << "queue is full" << endl;
      return false;
    }
    if(isEmpty()){
      front = rear = 0;
    }
    else{
      rear = (rear+1)%MAX;
    }
    queue[rear] = x;
    return true;
  }
  int dequeue(){
    if(isEmpty()){
      cout << "Queue is empty" << endl;
      return -1;
    }else if(front == rear){
      rear = front = -1;
      return queue[front];
    }
    else{
      int x = queue[front];
      front = (front+1)%MAX;
      return x;
    }
  }
};
int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << q.dequeue() << endl;
}
