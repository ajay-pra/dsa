// https://leetcode.com/problems/01-matrix/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>> ans(row, vector<int> (col,-1));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j] == 0){
                    q.push({{i,j}, 0});
                    ans[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int m = p.first.first;
            int n = p.first.second;
            int s = p.second;
            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};
            for(int i=0;i<4;i++){
                int nRow = m+delRow[i];
                int nCol = n+delCol[i];
                if(nRow>=0 && nRow < row && nCol>=0 && nCol<col && ans[nRow][nCol] == -1){
                    q.push({{nRow, nCol}, s + 1});
                    ans[nRow][nCol] = s + 1;
                }
            }
        }
        return ans;
    }
};



int main() {
    // 🔹 Hardcoded input matrix
    vector<vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };

    Solution obj;
    vector<vector<int>> result = obj.updateMatrix(mat);

    // 🔹 Print result
    cout << "Output Matrix:\n";
    for(auto &row : result){
        for(auto &val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}