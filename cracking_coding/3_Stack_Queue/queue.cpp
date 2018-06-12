#include <iostream>

using namespace std;

const int MAX = 100;

class Queue{
private:
    int a[MAX];
    int front, rear;
public:
    Queue(){
        front = -1;
        rear = -1;
    }
    bool isEmpty(){
        return (front == -1 && rear == -1);
    }

    bool isFull(){
        return front == MAX-1;
    }

    bool enqueue(int x){
        if(!isFull()){
            a[++front] = x;
            if(rear == -1){
                rear = 0;
            }
            return true;
        }
        else{
            cout << "queue is full" << endl;
            return false;
        }
    }

    bool dequeue(){
        cout << "rear " << rear << endl;
        cout << "front " << front << endl;
        if(!isEmpty()){
            if(rear == front){
                rear = front = -1;
            }else{
                rear ++;
            }

        }else{
            cout << "queue is empty" << endl;
            return false;
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
