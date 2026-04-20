// https://takeuforward.org/plus/dsa/problems/find-out-how-many-times-the-array-is-rotated?subject=dsa&approach=optimal


// same as finding index of minimum element

class Solution {
public:
    int findKRotation(vector<int> &nums) {
            int l = 0, h = nums.size() - 1;
            int ans = 0;
            while (l <= h) {
                int m = l + (h - l) / 2;
                if(nums[m]< nums[h]){
                    if(nums[ans]>nums[m]){
                        ans = m;
                    }
                    h = m - 1;
                }else{
                    if(nums[ans]>nums[l]){
                        ans = l;
                    }
                    l = m + 1;
                }
            }
            return ans;
        }
};