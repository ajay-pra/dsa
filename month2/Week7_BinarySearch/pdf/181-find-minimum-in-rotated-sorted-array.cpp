// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int l=0, h = n-1;
        while(l<=h){
            int m = (l+h)/2;
            if(nums[m]<nums[h]){
                ans = min(ans, nums[m]);
                h=m-1;
            }else{
                ans = min(nums[l], ans);
                l=m+1;
            }
        }
        return ans;
    }
};