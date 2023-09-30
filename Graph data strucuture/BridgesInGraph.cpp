//       BRIDGES IN GRAPH
//  -->>an edge in an unidrected connected graph is a bridge if removing it disconnects 
//     the graph,or siimply a bridge is an edge removing which increases the no of
//      disconnected components
//      TARJANS ALGORITHM
//  to implement this algorithm we need 3 data structure
// --> visited[]=to keep track of visited vertices
// -->>disc[0]=stands for discovery time and keep track when for first time that vertex is reached
// -->>low[]=stands for lowest and keep track of lowest possible time by which we can reach that vertex other than parent

#include<iostream>
#include<list>
#include<vector>
using namespace std;
class graph{
    int nvertices;
    list<int> *adj;
public:
graph(int nvertices);
void dfs(int u,vector<bool>& visited,vector<int>& disc,vector<int>& low,int parent);
void AddEdge(int v,int w);
void Bridge();


};
graph::graph(int nvertices){
    this->nvertices=nvertices;
    adj=new list<int>[nvertices];
}
void graph::AddEdge(int v,int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}
void graph::Bridge(){
    // mark all the vertices as not visited and low and disc  as -1
    vector<bool> visited(nvertices,false);
    vector<int> disc(nvertices,-1);
    vector<int> low(nvertices,-1);
    int parent=-1;
    // now calling dfs function to find bridges in graph
    for(int i=0;i<nvertices;i++){
        if(visited[i]==false){
            dfs(i,visited,disc,low ,parent);
        }
    }
}
void graph::dfs(int u,vector<bool>& visited,vector<int>& disc,vector<int>& low,int parent){
    static int time=0;
    visited[u]=true;
    disc[u]=low[u]=time++;
    // now traverse neighbour vertex of u
    list<int>:: iterator i;
    for( i=adj[u].begin();i!=adj[u].end();i++){
        int v=*i;
        // if v is parent of  u
        if(v==parent){
            continue;
        }
        // if v is visited
        if(visited[v]){
            low[u]=min(low[u],disc[v]);
        }
        // if v is not visited 
        else{
            parent=u;
            // make it visit
            dfs(v,visited,disc,low,parent);
            low[u]=min(low[u],low[v]);
        }
        if(low[v]>disc[u]){
            cout<<u<<" "<<v<<endl;
        }
    }
}
int main(){
    graph g(5);
    g.AddEdge(1,0);
        g.AddEdge(0,2);
        g.AddEdge(2,1);
        g.AddEdge(0,3);
        g.AddEdge(3,4);
        cout<<"bridge in graph are ";
        g.Bridge();
    



return 0;
}
// output of above code is 
// bridge in graph are 3 4
//                     0 3