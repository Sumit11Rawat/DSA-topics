class Solution {
  public:
//   a dfs function to travel depth wise
  void dfs(int node,vector<int>adjs[],int vis[]){
      vis[node]=1;
      for(auto i:adjs[node]){
          if(!vis[i]){
              dfs(i,adjs,vis);
          }
      }
      }
    int numProvinces(vector<vector<int>> adj, int V) {
        // create adjacency list from adjacency matrix
        vector<int> adjs[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1&&i!=j){
                    adjs[i].push_back(j);
                    adjs[j].push_back(i);
                }
            }
        }
        // create a vector which keeps track of visited. node
        int vis[V]={0};
        // create a variable count to keep track of no of provinces
        int count=0;
        // iterate throught the visited array to start our dfs traversal
        for(int i=0;i<V;i++){
            if(!vis[i]){
                count++;
                dfs(i,adjs,vis);
            }
        }
        return count;
    }
};
