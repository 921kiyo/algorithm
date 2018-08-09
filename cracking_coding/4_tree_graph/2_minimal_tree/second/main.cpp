#include <iostream>
#include <vector>

using namespace std;

class Node{
public:
  int data;
  Node* right;
  Node* left;
  Node(int value): data(value), right(nullptr), left(nullptr){}
};

void print(Node* node){
  if(node==nullptr){
    return;
  }
  cout << node->data << " ";
  print(node->right);
  print(node->left);
}

Node* createTreeBST(vector<int> arr, int low, int high){
  if(low > high){
    return nullptr;
  }
  int mid = (low+high)/2;
  Node* node = new Node(arr[mid]);
  node->right = createTreeBST(arr, mid+1, high);
  node->left = createTreeBST(arr, low, mid-1);
  return node;
}

Node* createTreeBST(vector<int> arr){
  if(arr.size() == 0){
    return nullptr;
  }
  return createTreeBST(arr, 0, (int)arr.size()-1);
}

int main(){
  vector<int> arr = {1,2,3,4,5,6,7};
  Node* root = createTreeBST(arr);
  print(root);
  return 0;
}
