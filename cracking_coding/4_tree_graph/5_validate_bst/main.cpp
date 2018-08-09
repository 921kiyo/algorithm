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

bool check_bst(Node* root){
  if(root == nullptr){
    return true;
  }
  Node* right = root->getRight();
  Node* left = root->getLeft();
  
  if(right->getData() > root->getData()){
    return false;
  }
  if(left->getData() > root->getData()){
    return false;
  }
  
  return check_bst(right);
  return check_bst(left);
}


int main(){
  Node root = Node(2);
  Node right = Node(3);
  Node left = Node(1);

  Node right2 = Node(2);
  Node left2 = Node(3);

  // right2.insertLeft(&left2);
  // right.insertRight(&right2);

  root.insertRight(&right);
  root.insertLeft(&left);

  cout << check_bst(&root) << endl;
  return 0;
}
