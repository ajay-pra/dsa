// https://leetcode.com/problems/rotting-oranges/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(vector<vector<int>>& grid, queue<pair<pair<int,int>,int>> &q, int row, int col, int &time){
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int m = p.first.first;
            int n = p.first.second;
            int t = p.second;
            int delRow[] = {0,-1,1,0};
            int delCol[] = {-1,0,0,1};
            for(int i=0;i<4;i++){
                int nRow = m+delRow[i];
                int nCol = n+delCol[i];
                if(nRow>=0 && nRow<row && nCol>=0 && nCol<col && grid[nRow][nCol] == 1){
                    grid[nRow][nCol] = 2;
                    q.push({{nRow,nCol},t+1});
                    time = max(time, t+1);
                }
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        int time = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                }
            }
        }
        bfs(grid, q, row, col, time);
        bool flag = true;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 1){
                    flag = false;
                }
            }
        }
        return flag ? time : -1;
    }
};


int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };
    Solution obj;
    int result = obj.orangesRotting(grid);
    cout << "Minimum time to rot all oranges: " << result << endl;
    return 0;
}