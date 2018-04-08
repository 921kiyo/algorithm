// https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
#include<iostream>
#include<list>

using namespace std;


class Graph
{
  int V; // Not of vertices
  list<int> *adj; // Pointer to an array containing adjacency lists
  void DFSUtil(int v, bool visited[]); // a recursive function used by DFS

public:
  Graph(int V);

  void addEdge(int v, int w);

  void DFS(int s);
};

Graph::Graph(int V){
  this->V = V;
  adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
  adj[v].push_back(w);
}

void Graph::DFSUtil(int v, bool visited[]){
  // Mark the current node as visited and print it
  visited[v] = true;
  cout << v << " ";

  // Resurse for all the vertices adjacent to this vertex
  list<int>::iterator i;
  for(i = adj[v].begin(); i != adj[v].end(); ++i){
    if(!visited[*i]){
      DFSUtil(*i, visited);
    }
  }
}

void Graph::DFS(int s){
  // Make all the vertices as not visited
  bool *visited = new bool[V];
  for(int i = 0; i < V; i++){
    visited[i] = false;
  }

  for(int i = 0; i < V; i++){
    if(visited[i] == false){
      DFSUtil(i, visited);
    }
  }
}

int main(){
  Graph g(4);
  g.addEdge(0,1);
  g.addEdge(0,2);
  g.addEdge(1,2);
  g.addEdge(2,0);
  g.addEdge(2,3);
  g.addEdge(3,3);
  cout << "Following is Depth First Traversal "
         << "(starting from vertex 2) \n";
  g.DFS(2);

  return 0;
}
