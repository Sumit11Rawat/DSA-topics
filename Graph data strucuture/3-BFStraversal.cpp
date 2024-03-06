    //   BFS-Breadth First Search

// -->>The Breadth First Search (BFS) algorithm is used to search a graph data structure
//     for a node that meets a set of criteria. It starts at the root of the graph 
//     and visits all nodes at the current depth level before moving on to the nodes at the next depth level.

// The only catch here is, that, unlike trees, graphs may contain cycles, so we may come to the same node again.
//  To avoid processing a node more than once, we divide the vertices into two categories:
// Visited and
// Not visited.

// -->>Starting from the root, all the nodes at a particular level are visited first and then the
//     nodes of the next level are traversed till all the nodes are visited.
// -->>To do this a queue is used. All the adjacent unvisited nodes of the current level are pushed into the queue and the nodes of the current level are marked visited and popped from the queue.

#include<iostream>
using namespace std;
#include<vector>
#include<queue>
const int N=1e5+10;
int visited[N];
vector<int> graph[N];
int main(){
    // intialitsing visited array with 0;
    for(int i=0;i<N;i++){
        visited[N]=0;
    }
    int nvertices;
    cout<<"enter the no of nodes in a graph ";
    cin>>nvertices;
    //  making the edge relation between node
    for(int i=0;i<nvertices;i++){
        int vertex1,vertex2;
        cout<<"enter the vertexes of graph ";
        cin>>vertex1>>vertex2;
        cout<<"fine"<<endl;
        graph[vertex1].push_back(vertex2);
        graph[vertex2].push_back(vertex1);
    }
    cout<<"sequence of bfs traversal is "<<endl;
    // defining a queue to push the level wise traversal
    queue<int>q;
    q.push(1);
    // whenever we push into queue we mark it visited
    visited[1]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<endl;
        vector<int>::iterator it;
        // check if iterator of vector is visited or not 
        // if not then push it into queue and mark it visited
        for( it=graph[node].begin();it!=graph[node].end();it++){
            if(!visited[*it]){
                visited[*it]=1;
                q.push(*it);
            }
        }
        
        
    }
    
    
    return 0;
}
