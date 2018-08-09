#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

class Tree{

};
int main(){
  vector<int> arr = {1,2,3,4,5,6,7};
  Node* root = createTreeBST(arr);
  preOrder(root, 0);


  return 0;
}
