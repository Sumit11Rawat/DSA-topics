#include<iostream>
using namespace std;
#include<unordered_map>
#include<list>
#include<stack>
#include<vector>
#include<limits.h>
class graph{
public:
unordered_map<int,list<pair<int,int>>> adj;
void AddEdge(int u,int v,int weight){
    pair<int,int> p=make_pair(v,weight);
    adj[u].push_back(p);
}
void printAdj(){
    for(auto i:adj){
        cout<<i.first<<"->";
        for(auto j:i.second){
            cout<<"("<<j.first<<","<<j.second<<")";
        }
        cout<<endl;
    }
}
void dfs(int node,unordered_map<int,bool> &visited,stack<int> &topo){
    visited[node]=true;
    for(auto neighbour:adj[node]){
        if(!visited[neighbour.first]){
            dfs(neighbour.first,visited,topo);
        }
    }
    topo.push(node);
}
void getshortestpath(int source,vector<int>& distance,stack<int>& topo){
distance[source]=0;



while(!topo.empty()){
int top=topo.top();
topo.pop();
if(distance[top]!=INT_MAX){
for(auto i:adj[top]){
    if(distance[top]+i.second<distance[i.first]){
        distance[i.first]=distance[top]+i.second;
    }
}
}


}
}
};
int main(){

graph g;
g.AddEdge(0,1,5);
g.AddEdge(0,2,3);
g.AddEdge(1,2,2);
g.AddEdge(1,3,6);
g.AddEdge(2,3,7);
g.AddEdge(2,4,4);
g.AddEdge(2,5,2);
g.AddEdge(3,4,-1);
g.AddEdge(4,5,-2);
g.printAdj();
// topological sort
int nvertices=6;

unordered_map<int,bool> visited;
stack<int> s;
for(int i=0;i<nvertices;i++){
    if(!visited[i]){
        g.dfs(i,visited,s);
    }
}
int source=1;
vector<int> distance(nvertices);
for(int i=0;i<nvertices;i++){
    distance[i]=INT_MAX;
}
g.getshortestpath(source,distance,s);
cout<<"ans is "<<endl;
for(int i=0;i<distance.size();i++){
    cout<<distance[i]<<" ";
}
cout<<endl;
    return 0;
}