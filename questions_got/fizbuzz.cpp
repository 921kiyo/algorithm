#include <iostream>

using namespace std;

void fizzbuzz(int max){
    for(int i = 0; i < max; i++){
        if(i%3==0 && i%5 == 0){
            cout << "FizzBuzz" << endl;
        }
        else if(i%3 == 0){
            cout << "Fizz" << endl;
        }
        else if(i%5==0){
            cout << "Buzz" << endl;
        }
        else{
            cout << i << endl;
        }
    }
}

int main(){
    fizzbuzz(30);
    return 0;
}