// https://takeuforward.org/plus/dsa/problems/find-row-with-maximum-1's?subject=dsa&approach=binary-search&tab=submissions


class Solution {
  public:  
  int firstOccurance(vector<int> &nums, int n){
        int l = 0, h = nums.size()-1;
        int ans = nums.size();
        while(l<=h){
            int m = (l+h)/2;
            if(nums[m] == n){
                ans = m;
                h = m-1;
            }else if(nums[m]<n){
                l=m+1;
            }else{
                h=m-1;
            }
        }
        return ans;
    }

  int rowWithMax1s(vector < vector < int >> & mat) {
        int n = mat.size();
        int m = mat[0].size();
        int maxOnes = 0;
        int rowIndex = -1;
        for(int i = 0; i < n; i++){
            int firstOneIndex = firstOccurance(mat[i], 1);
            int onesCount = m - firstOneIndex;
            if(onesCount > maxOnes){
                maxOnes = onesCount;
                rowIndex = i;
            }
        }
        return rowIndex;
  }
};