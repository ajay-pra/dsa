// https://takeuforward.org/plus/dsa/problems/traversal-techniques?subject=dsa&approach=dfs&tab=submissions

#include <bits/stdc++.h>
using namespace std;

// In this code, we first convert the given edge list into an adjacency list, which efficiently represents the graph.
// For DFS (Depth First Search), we use recursion: start from a node, mark it visited, add it to the result, and recursively explore all its unvisited neighbors—this goes deep into one branch before backtracking.
// For BFS (Breadth First Search), we use a queue: start from a node, push it into the queue, and process nodes level by level by visiting all neighbors before moving deeper. Both methods use a visited array to avoid revisiting nodes and prevent infinite loops.

class Solution {
public:

    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &ans){
        ans.push_back(node);
        vis[node] = 1;

        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis, ans);
            }
        }
    }  

    vector<int> dfsOfGraph(int V, vector<vector<int>> &edges) {
        vector<int> ans;
        vector<int> vis(V, 0);
        vector<vector<int>> adj(V);

        // build graph
        for(auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        dfs(0, adj, vis, ans);
        return ans;
    }
    
    void bfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &ans){
        queue<int> q;
        q.push(node);
        vis[node] = 1;

        while(!q.empty()){
            int front = q.front();
            q.pop();

            ans.push_back(front);

            for(auto it : adj[front]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }

    vector<int> bfsOfGraph(int V, vector<vector<int>> &edges) {
        vector<int> ans;
        vector<int> vis(V, 0);
        vector<vector<int>> adj(V);

        // build graph
        for(auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        bfs(0, adj, vis, ans);
        return ans;
    }
};

int main() {
    int V = 5;
    vector<vector<int>> edges = {
        {0,1}, {0,2}, {1,3}, {1,4}
    };

    Solution obj;

    vector<int> dfsAns = obj.dfsOfGraph(V, edges);
    vector<int> bfsAns = obj.bfsOfGraph(V, edges);

    cout << "DFS: ";
    for(auto x : dfsAns) cout << x << " ";

    cout << "\nBFS: ";
    for(auto x : bfsAns) cout << x << " ";

    return 0;
}