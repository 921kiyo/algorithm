#include <iostream>

using namespace std;

struct Node{
  int data;
  Node* next;
};

class List{
private:
  Node* head;
public:
  List(){head = NULL;}

  void append(int data){
    Node* temp = new Node;
    temp->next = head;
    temp->data = data;
    head = temp;
  }
  int get_size(){
    Node* node =this->head;
    int count = 0;
    while(node != NULL){
      count++;
      node = node->next;
    }
    return count;
  }
  Node* return_kth(Node* head, int k, int& i){
    if(head == NULL){
      return NULL;
    }
    Node* nd = return_kth(head->next, k, i);
    i = i+1;
    cout << "i " << i << endl;
    if(i == k){
      return head;
    }
    return nd;
  }

  int return_kth(int k){
    int i = 0;
    Node* answer = return_kth(this->head, k, i);
    cout << answer->next->data << endl;
    return answer->data;
  }
};

int main(){
  List list;
  list.append(1);
  list.append(2);
  list.append(3);
  list.append(4);
  list.append(5);
  list.append(6);

  cout << list.return_kth(2) << endl;
  return 0;
}
