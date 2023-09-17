//      Adjacency Matrix

// -->>An adjacency matrix is a way of representing a graph as a matrix of booleans (0's and 1's). 
//     A finite graph can be represented in the form of a square matrix on a computer, 
//     where the boolean value of the matrix indicates if there is a direct path between two vertices.
// Pros of Adjacency Matrix

//    The basic operations like adding an edge, removing an edge, and checking whether there is an edge from vertex i to vertex j are extremely time efficient, constant time operations.
//    If the graph is dense and the number of edges is large, an adjacency matrix should be the first choice. Even if the graph and the adjacency matrix is sparse, we can represent it using data structures for sparse matrices.
//    The biggest advantage, however, comes from the use of matrices. The recent advances in hardware enable us to perform even expensive matrix operations on the GPU.
//    By performing operations on the adjacent matrix, we can get important insights into the nature of the graph and the relationship between its vertices.

// Cons of Adjacency Matrix

//    The VxV space requirement of the adjacency matrix makes it a memory hog. 
//    Graphs out in the wild usually don't have too many connections and
//    this is the major reason why adjacency lists are the better choice for most tasks.
//    While basic operations are easy, operations like inEdges and outEdges are expensive when using the adjacency matrix representation.

#include<iostream>
using namespace std;

 int main(){
     int nvertices;
     cout<<"Enter the no of vertices ";
     cin>>nvertices;
     int vertices[nvertices];
     cout<<"enter the nodes present in graph ";
     for(int i=0;i<nvertices;i++){
        cin>>vertices[i];
     }
    //  defining matrix
    int graph[nvertices+1][nvertices+1];
    // setting all the value of matrix as 0;
    for(int i=0;i<nvertices+1;i++){
        for(int j=0;j<nvertices+1;j++){
        graph[i][j]=0;
        }
        cout<<endl;
    }
// making the edge relation between node
for(int i=0;i<nvertices;i++){
int vertex1,vertex2;
cout<<"enter the vertex to add ";
cin>>vertex1>>vertex2;
    for(int i=0;i<nvertices;i++){
        for(int j=0;j<nvertices;j++){
        graph[vertex1][vertex2]=1;
        graph[vertex2][vertex1]=1;
    
    }
    }
}
     cout<<"the adjacency matrix is "<<endl;
    
    //  printing the adjacency list
    for(int i=0;i<nvertices+1;i++){
        for(int j=0;j<nvertices+1;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
     return 0;
 }
 