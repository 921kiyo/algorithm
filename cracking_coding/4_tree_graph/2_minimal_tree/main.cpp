#include <iostream>
#include <vector>

using namespace std;

class Node{
public:
  int data;
  Node* left;
  Node* right;
  Node(int d): data(d){
    left = right = nullptr;
  }
};

void preOrder(Node* node){
  if(node == nullptr){
    return;
  }
  cout << node->data << " ";
  preOrder(node->left);
  preOrder(node->right);
}

Node* createTreeBST(vector<int> arr, int low, int high){
  if (low > high){
    return nullptr;
  }
  int mid = (low + high)/2;
  Node* node = new Node(arr[mid]);
  node->right = createTreeBST(arr, mid+1, high);
  node->left = createTreeBST(arr, low, mid-1);
  return node;
}

Node* createTreeBST(vector<int> arr){
  if (arr.size() == 0){
    return nullptr;
  }
  return createTreeBST(arr, 0, (int)arr.size()-1);
}

int main(){
  int length = 7;
  int A[length] = {1,2,3,4,5,6,7};
  vector<int> arr (A, A+sizeof(A)/sizeof(A[0]));

  Node* root = createTreeBST(arr);
  preOrder(root);
  return 0;
}
