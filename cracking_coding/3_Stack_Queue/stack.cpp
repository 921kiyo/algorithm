#include <iostream>
#include <string>

using namespace std;

const int MAX = 1000;

class Stack{
    int top;
public:
    int a[MAX];

    Stack() { top= -1 ;}
    bool push(int x){
        if(top > MAX){
            cout << "Stack overflow" << endl;
            return false;
        }else{
            a[++top] = x;
            return true;
        }
    }
    int pop(){
        if(top < 0){
            cout << "Stack underflow" << endl;
            return 0;
        }
        else{
            int x = a[top--];
            return x;
        }
    }
    bool isEmpty(){
        return (top < 0);
    }
};

int main(){
    struct Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " popped" << endl;
    return 0;
}
