// https://leetcode.com/problems/detect-cycles-in-2d-grid/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(vector<vector<char>>& grid, int i, int j, vector<vector<int>> &vis, bool &ans){
        queue<pair<pair<int,int>, pair<int,int>>> q;
        q.push({{i,j},{-1,-1}});
        vis[i][j] = 1;
        int row = grid.size();
        int col = grid[0].size();
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int r = p.first.first;
            int c = p.first.second;
            int pr = p.second.first;
            int pc = p.second.second;
            int delRow[4] = {-1, 0, 1, 0};
            int delCol[4] = {0, 1, 0, -1};
            for(int i=0;i<4;i++){
                int nr = r+delRow[i];
                int nc = c+delCol[i];
                if(nr>=0 && nr<row && nc>=0 && nc<col && grid[nr][nc] == grid[r][c]){
                    if(!vis[nr][nc]){
                        vis[nr][nc] = 1;
                        q.push({{nr, nc}, {r, c}});
                    }else if(nr != pr || nc != pc) {
                        ans = true;
                    }
                }
            }
        }
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> vis(row, vector<int>(col,0));
        bool ans = false;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!vis[i][j]){
                    bfs(grid, i, j, vis, ans);
                }
            }
        }
        return ans;
    }
};


int main() {

    // 🔹 Hardcoded grid
    vector<vector<char>> grid = {
        {'a','a','a','a'},
        {'b','b','b','a'},
        {'b','b','b','a'},
        {'a','a','a','a'}
    };

    Solution obj;
    bool result = obj.containsCycle(grid);

    if(result) cout << "Cycle Found\n";
    else cout << "No Cycle\n";

    return 0;
}