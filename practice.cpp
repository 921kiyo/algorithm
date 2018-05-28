#include <iostream>
#include <list>

using namespace std;

struct tree {
  int x;
  tree * l;
  tree * r;
};


#include<unordered_map>

int solution_util(tree *T, unordered_map<int, int> hashtable){
    if(!T){
     return hashtable.size();

    }
    hashtable[T->x] += 1;

    int max_path = max(solution_util(T->l, hashtable), solution_util(T->r, hashtable));

    // hashtable[T->x]--;
    // if(hashtable[T->x] == 0){
    //     hashtable.erase(T->x);
    // }


    return max_path;
}

int solution(tree * T) {
    // write your code in C++14 (g++ 6.2.0)
    if(!T){
        return 0;
    }

    unordered_map<int, int> hashtable;

    return solution_util(T, hashtable);
}

int main(){
  cout << "hello" << endl;
  return 0;
}
