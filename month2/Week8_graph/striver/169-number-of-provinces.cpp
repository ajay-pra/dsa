// https://leetcode.com/problems/number-of-provinces/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(int node, vector<int> adjLs[], vector<int> &vis) {
        vis[node] = 1;
        queue<int> q;
        q.push(node);

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            for (auto adjNode : adjLs[i]) {
                if (!vis[adjNode]) {
                    vis[adjNode] = 1;
                    q.push(adjNode);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();

        vector<int> adjLs[V];

        // Convert matrix to adjacency list
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                }
            }
        }

        vector<int> vis(V, 0);
        int cnt = 0;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                cnt++;
                bfs(i, adjLs, vis);
            }
        }
        return cnt;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    int result = obj.findCircleNum(isConnected);
    cout << "Number of Provinces: " << result << endl;
    return 0;
}