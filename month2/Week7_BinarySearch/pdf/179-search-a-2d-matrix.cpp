// https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int l = 0, h = row*col-1;
        while(l<=h){
            int m = (l+h)/2;
            int r = m/col;
            int c = m%col;
            if(matrix[r][c] == target){
                return true;
            }else if(matrix[r][c] < target){
                l = m+1;
            }else{
                h = m-1;
            }
        }
        return false;
    }
};