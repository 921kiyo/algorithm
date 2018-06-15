#include <iostream>
#include <cstdlib>

#include <cstring>


using namespace std;

struct Node;
typedef Node *Node_ptr;

struct Node{
  int integer;
  Node *next;
};


void assign_new_node(Node_ptr &a_node){
  a_node = new (nothrow) Node;
  if(a_node == NULL){
    cout << "no more memory" << endl;
    exit(1);
  }
}

void assign_list(Node_ptr &a_list){
  Node_ptr current_node, last_node;

  assign_new_node(a_list);
  cout << "Enter the first integer (or . to end the list): ";
  cin >> a_list->integer;
  if(!strcmp(".", a_list->integer)){
    delete a_list;
    a_list = NULL;
  }
  current_node = a_list;

  while(current_node != NULL){
    assign_new_node(last_node);
    cout << "Enter the next integer (or . to end the list): ";
    cin >> last_node->integer;
    if(!strcmp(".", last_node->integer)){
      delete last_node;
      last_node = NULL;
    }
    current_node->next = last_node;
    current_node = last_node;
  }
}
