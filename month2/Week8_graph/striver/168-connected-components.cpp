// https://takeuforward.org/plus/dsa/problems/connected-components?subject=dsa&category=graph&subcategory=theory-and-traversals&approach=dfs


class Solution {
  public:
    void bfs(int node, vector<int> &ans, int vis[], vector<vector<int>> &adj){
        ans.push_back(node);
        vis[node] = 1;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto it:adj[front]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }
    int findNumberOfComponent(int V, vector<vector<int>> &edges) {
        vector<int> ans;
        vector<vector<int>> adj(V);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int vis[V] = {0};
        int count = 0;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                count++;
                bfs(i, ans, vis, adj);
            }
        }
        return count;
    }
};