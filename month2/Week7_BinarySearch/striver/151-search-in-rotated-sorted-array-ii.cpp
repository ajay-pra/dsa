// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, h = nums.size()-1;
        while(l<=h){
            int m = (l+h)/2;
            if(nums[m] == target) return true;
            if(nums[l] == nums[m] && nums[m] == nums[h]){
                l++;
                h--;
                continue;
            }
            if(nums[m]<=nums[h]){
                if(target>nums[m] && target<=nums[h]){
                    l=m+1;
                }else{
                    h=m-1;
                }
            }else{
                if(nums[l]<=target && target<nums[m]){
                    h=m-1;
                }else{
                    l=m+1;
                }
            }
        }
        return false;
    }
};