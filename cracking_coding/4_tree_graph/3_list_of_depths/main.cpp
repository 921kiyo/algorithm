#include <iostream>

using namespace std;

class Node{
public:
  int data;
  Node* right;
  Node* left;
  Node(int d):data(d), right(nullptr), left(nullptr){}
};

int main(){
  return 0;
}
