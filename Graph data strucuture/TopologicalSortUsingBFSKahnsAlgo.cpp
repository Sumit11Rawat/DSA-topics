// -->>following code is used to implement topological sort using 
//     bfs technique
// -->>same code can be used to detect cycle in a graph


#include<iostream>
using namespace std;
#include<list>
#include<vector>
#include<queue>
class graph{
int nvertices;
list<int>* adj;
// conructor
  public:
   graph(int nvertices);

    void AddEdges(int u,int v);
    void TopologicalSort();
};

graph::graph(int nvertices){
    this->nvertices=nvertices;
    adj=new list<int>[nvertices];
}
void graph::AddEdges(int u,int v){
    adj[u].push_back(v);
}
void graph::TopologicalSort(){
// creating an vector to store indegree of all vertices
vector<int> in_degree(nvertices,0);
// traverse the adjency list to fill indegree of vertices
for(int u=0;u<nvertices;u++){
    list<int>::iterator itr;
    for(itr=adj[u].begin();itr!=adj[u].end();itr++){
in_degree[*itr]++;
    }
}
    // now create a queue
    queue<int> q;
    for(int i=0;i<nvertices;i++){
        if(in_degree[i]==0){
            q.push(i);
        }
    }

    int count=0;
    // create a vector to store result of topological sort;
    vector<int> top_order;
    // now dequeue vertices from queue and enqueue adjacent if indegree of adjacent becomes 0
while(!q.empty()){
    // extract front of queue
    // and add it to topological order
    int u=q.front();
    q.pop();
    top_order.push_back(u);
    // now iterate through all the neighbourhood nodes of dequeued nodes
// and decrease their indegree by 1
list<int>::iterator itr;
for(itr=adj[u].begin();itr!=adj[u].end();itr++){
    if(--in_degree[*itr]==0){
        q.push(*itr);
    }
}
count++;
}
if(count!=nvertices){
    cout<<"there exist a cycle in graph"<<endl;
    return;
}
else{
    cout<<"there doesn't exist a cycle in graph "<<endl;
}
// print topological order


cout<<"Following is the topological sort order "<<endl;
for(int i=0;i<top_order.size();i++){
    cout<<top_order[i]<<" ";
    cout<<endl;


}
}
int main(){
 graph g(6);
g.AddEdges(5,2);
g.AddEdges(5,0);
g.AddEdges(4,0);
g.AddEdges(4,1);
g.AddEdges(2,3);
g.AddEdges(3,1);
g.TopologicalSort();

return 0;
}
// there doesn't exist a cycle in graph 
// Following is the topological sort order
// 4
// 5
// 2
// 0
// 3
// 1