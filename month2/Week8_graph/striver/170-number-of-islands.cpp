// https://leetcode.com/problems/number-of-islands/

#include <bits/stdc++.h>
using namespace std;

// This problem is solved using Breadth-First Search (BFS). We iterate through every cell of the grid, and whenever we find a cell with '1' (land) that has not been visited, we treat it as the start of a new island and increment the island count. From that cell, we perform BFS to explore all connected land cells in 4 directions (up, down, left, right), marking them as visited so they are not counted again. This ensures that each connected component of land is counted exactly once as an island. The overall time complexity is O(n × m) since each cell is visited at most once.

class Solution {
public:
    void bfs(vector<vector<char>>& grid, int i, int j, vector<vector<int>> &vis){
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;
        int row = grid.size();
        int col = grid[0].size();
        while(!q.empty()){
            auto p = q.front();
            int m = p.first;
            int n = p.second;
            q.pop();
            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};
            for(int k = 0; k < 4; k++){
                int newRow = m + delRow[k];
                int newCol = n + delCol[k];
                if(newRow>=0 && newRow<row && newCol>=0 && newCol<col && grid[newRow][newCol] == '1' && !vis[newRow][newCol]){
                    vis[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> vis(row, vector<int>(col,0));
        int cnt = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    bfs(grid, i, j, vis);
                }
            }
        }
        return cnt;
    }
};


int main() {
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    Solution obj;
    cout << "Number of Islands: " << obj.numIslands(grid) << endl;

    return 0;
}