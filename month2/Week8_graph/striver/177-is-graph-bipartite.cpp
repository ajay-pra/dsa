// https://leetcode.com/problems/is-graph-bipartite/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(int i, vector<vector<int>> &graph, vector<int> &color, bool &ans){
        queue<int> q;
        q.push(i);
        color[i] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : graph[node]){
                if(color[it] == -1){
                    color[it] = !color[node];
                    q.push(it);
                }
                else if(color[it] == color[node]){
                    ans = false;
                }
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);

        bool ans = true;

        for(int i = 0; i < V; i++){
            if(color[i] == -1){
                bfs(i, graph, color, ans);
                if(!ans) return false;
            }
        }
        return ans;
    }
};

int main() {

    // 🔹 Hardcoded graph (Bipartite)
    vector<vector<int>> graph1 = {
        {1,3},   // 0
        {0,2},   // 1
        {1,3},   // 2
        {0,2}    // 3
    };

    // 🔹 Hardcoded graph (NOT Bipartite - odd cycle)
    vector<vector<int>> graph2 = {
        {1,2},   // 0
        {0,2},   // 1
        {0,1}    // 2
    };

    Solution obj;

    cout << "Graph1: ";
    if(obj.isBipartite(graph1)) cout << "Bipartite\n";
    else cout << "Not Bipartite\n";

    cout << "Graph2: ";
    if(obj.isBipartite(graph2)) cout << "Bipartite\n";
    else cout << "Not Bipartite\n";

    return 0;
}