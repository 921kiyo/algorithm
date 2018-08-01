#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph{
public:
  int V;
  vector<int> *adj;

  Graph(int v): V(v){
    adj = new vector<int>[V];
  }

  void addEdge(int x, int y){
    adj[x].push_back(y);
  }

  bool isRoute_dfs(int x, int y){
    vector<bool>visited(V, false);
    if (x == y){
      return true;
    }
    DFS_util(x, visited);

    return visited[y];
  }

  void DFS_util(int x, vector<bool> &visited){
    visited[x] = true;
    vector<int>::iterator i;
    for(i = adj[x].begin(); i != adj[x].end(); ++i){
      if(!visited[*i]){
        DFS_util(*i, visited);
      }
    }
  }

  // bool isRoute_bfs(int x, int y){
  //   vector<bool>visited(V, false);
  //   queue<int> q;

  //   q.push(x);
  //   while(!q.empty()){
  //     int curr = q.front();
  //     if(curr == y){
  //       return true;
  //     }

  //     q.pop();
  //     visited[curr] = true;
  //     int n_size = adj[curr].size();

  //     for(int i = 0; i < n_size; ++i){
  //       if(!visited[adj[curr][i]]){
  //         q.push(adj[curr][i]);
  //       }
  //     }
  //   }
  //   return false;
  // }

};

int main(){
	
    Graph g(6);	
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

/*	
	Test graph :
	0 <---4---->1
	^ 			^
	|			|
	|			|
    5---->2---->3 
*/
    cout<<g.isRoute_dfs(5,4)<<endl; // false
    cout<<g.isRoute_dfs(5,1)<<endl; // true

    return 0;
}
