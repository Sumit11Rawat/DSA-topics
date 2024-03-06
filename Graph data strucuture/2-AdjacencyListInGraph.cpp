// 
    //  Adjacency List
// -->>An adjacency list represents a graph as an array of linked lists. 
// -->>The index of the array represents a vertex and each element in its linked list represents
//     the other vertices that form an edge with the vertex.

// Pros of Adjacency List
// -->>An adjacency list is efficient in terms of storage because we only need to store the values for the edges. 
// -->>For a sparse graph with millions of vertices and edges, this can mean a lot of saved space.It also
//    helps to find all the vertices adjacent to a vertex easily.

//   Cons of Adjacency List
// Finding the adjacent list is not quicker than the adjacency matrix 
// because all the connected nodes must be first explored to find them.
#include<iostream>
using namespace std;
#include<vector>
void AddEdges(int vertex1,int vertex2,vector<int> graph[]){
    graph[vertex1].push_back(vertex2);
    graph[vertex2].push_back(vertex1);
}
// printing the adjacency list
void PrintAdjList(vector<int> graph[], int nvertices) {
  for (int d = 0; d < nvertices; ++d) {
    cout << "\n Vertex "
       << d << ":";
    for (auto x : graph[d])
      cout << "-> " << x;
    printf("\n");
  }
}
int main(){
int nvertices;
cout<<"enter the no of vertices in graph: ";
cin>>nvertices;

// create a array of vertex to store all element connected to vertex
vector<int> graph[nvertices];
// adding element to the list
AddEdges(1,2,graph);
AddEdges(2,3,graph);
PrintAdjList(graph,nvertices);


    return 0;
}
