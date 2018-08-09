#include <iostream>
#include <algorithm>
#include <cstdlib>

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
};

int checkHeight(Node* root){
  if(root == nullptr){
    return 0;
  }

  int leftHeight = checkHeight(root->getLeft());
  if(leftHeight == -1){
    return -1;
  }

  int rightHeight = checkHeight(root->getRight());
  if(rightHeight == -1){
    return -1;
  }

  int diff = leftHeight - rightHeight;
  if(abs(diff) > 1){
    return -1;
  }else{
    return max(rightHeight, leftHeight) + 1;
  }
}
// int getHeight(Node* root){
//   if(root == nullptr){
//     return 0;
//   }
//   return max(getHeight(root->getLeft()), getHeight(root->getRight())) + 1;
// }
//
// bool check_balanced(Node* root){
//   if (root == nullptr) return true;
//   int heightDiff = getHeight(root->getRight()) - getHeight(root->getLeft());
//   if(abs(heightDiff) > 1){
//     return false;
//   }else{
//     return check_balanced(root->getLeft()) && check_balanced(root->getRight());
//   }
// }

int main(){
  Node root = Node(1);
  Node right = Node(2);
  Node left = Node(3);
  Node right2 = Node(2);
  Node left2 = Node(3);
  right2.insertLeft(&left2);
  right.insertRight(&right2);
  root.insertRight(&right);
  root.insertLeft(&left);
  // cout << check_balanced(&root) << endl;
  cout << checkHeight(&root) << endl;
  return 0;
}
