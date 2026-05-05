// https://leetcode.com/problems/flood-fill/



class Solution {
public:
    void bfs(vector<vector<int>>& image, int sr, int sc, int row, int col, int color, int oldColor){
        queue<pair<int,int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        int rowRange[] = {-1, 0, 1, 0};
        int colRange[] = {0, -1, 0, 1};
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int m = p.first;
            int n = p.second;
            for(int k=0;k<4;k++){
                int newRow = m+rowRange[k];
                int newCol = n+colRange[k];
                if(newRow>=0 && newRow<row && newCol>=0 && newCol<col && image[newRow][newCol] == oldColor){
                    image[newRow][newCol] = color;
                    q.push({newRow, newCol});
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        if(oldColor == color) return image;
        int row = image.size();
        int col = image[0].size();
        bfs(image, sr, sc, row, col, color, oldColor);
        return image;
    }
};