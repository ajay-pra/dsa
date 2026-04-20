// https://leetcode.com/problems/search-a-2d-matrix/

#include <bits/stdc++.h>
using namespace std;
// This approach treats the 2D matrix as a flattened sorted 1D array because each row is sorted and the first element of every row is greater than the last element of the previous row. We apply binary search on indices from 0 to row * col - 1. For any middle index m, we convert it back to 2D coordinates using row = m / col and col = m % col. Based on the comparison with the target, we adjust the search space just like standard binary search. This allows us to efficiently search without explicitly flattening the matrix.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int l = 0, h = row * col - 1;

        while(l <= h){
            int m = l + (h - l) / 2;

            int r = m / col;   // row index
            int c = m % col;   // column index

            if(matrix[r][c] == target){
                return true;
            }
            else if(matrix[r][c] < target){
                l = m + 1;
            }
            else{
                h = m - 1;
            }
        }
        return false;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target = 3;

    if(obj.searchMatrix(matrix, target))
        cout << "Element found" << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}