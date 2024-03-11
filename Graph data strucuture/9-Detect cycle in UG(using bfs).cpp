class Solution {
  public:
//   a simple function to perform bfs traversal
  bool bfs(int num,vector<int>adj[],vector<int>&vis){
    //   mark the incoming node as visited
      vis[num]=1;
    //   create a queue of pair where first store node while second is its parent
      queue<pair<int,int>>q;
    //   push node in queue
      q.push({num,-1});
      while(!q.empty()){
        //   store pair value 
          int node=q.front().first;
          int parent=q.front().second;
          q.pop();
        //   now traverse all neighbour of node via adjacency list
          for(auto i:adj[node]){
            //   if it isnt visited visit it and push in queue 
              if(!vis[i]){
                  vis[i]=1;
                  q.push({i,node});
              }
            //   if it is visited but it is the parent then we dont consider it as it has come
            // from the parent only 
            // rather if it is visited but not the parent this mean someone else visited it before 
            // this node
            // this proves the present of cycle hence return true
              else if(i!=parent){
                  return true;
              }
          }
      }
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // create a vector visited to keep track of visited nodes
        vector<int>vis(V,0);
        // iteratively visit every node 
        // as it is possible that all nodes are not connected 
        // but rather broken in components
        for(int i=0;i<V;i++){
            // find node that isnt visited and do bfs traversal on it
            if(!vis[i]){
                
                if(bfs(i,adj,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};

