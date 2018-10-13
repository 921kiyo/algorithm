#include <iostream>

using namespace std;

class Node{
private:
  int data;
  Node* right;
  Node* left;
public:
  Node(int d):data(d), right(nullptr), left(nullptr){}
  void insertRight(Node* r){right = r;}
  void insertLeft(Node* l){left = l;}
  Node* getRight(){return right;}
  Node* getLeft(){return left;}
  int getData(){return data;}
};

int find_next_node(Node* root){
  if(root->getRight() == nullptr){
    return -1;
  }
  Node * answer = root->getRight();
  while(answer->getLeft() != nullptr){
    answer = answer->getLeft();
  }
  return answer->getData();
}

int main(){
  Node left = Node(1);
  Node root = Node(2);
  Node right = Node(4);

  Node right2 = Node(5);
  Node left2 = Node(3);
  //
  // right.insertLeft(&left2);
  right.insertRight(&right2);

  root.insertRight(&right);
  root.insertLeft(&left);

  // This must be 3
  cout << find_next_node(&root) << endl;

  return 0;
}
