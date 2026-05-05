// https://leetcode.com/problems/surrounded-regions/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>>vis(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if((i==0 || i==row-1 || j==0 || j==col-1) && board[i][j] == 'O'){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
        int delRow [] = {-1,0,1,0};
        int delCol [] = {0,-1,0,1};
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int m = p.first;
            int n = p.second;
            for(int i=0;i<4;i++){
                int nRow = m+delRow[i];
                int nCol = n+delCol[i];
                if(nRow>=0 && nRow<row && nCol>=0 && nCol<col && !vis[nRow][nCol] && board[nRow][nCol] == 'O'){
                vis[nRow][nCol] = 1;
                q.push({nRow,nCol});
            }
        }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};


int main() {
    // 🔹 Hardcoded board
    vector<vector<char>> board = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };

    Solution obj;
    obj.solve(board);

    // 🔹 Print result
    cout << "Final Board:\n";
    for(auto &row : board){
        for(auto &ch : row){
            cout << ch << " ";
        }
        cout << endl;
    }

    return 0;
}