// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstO(vector<int>& nums, int target){
        int l = 0, h = nums.size() - 1;
        int ans = -1;

        while(l <= h){
            int m = l + (h - l) / 2;

            if(nums[m] == target){
                ans = m;
                h = m - 1; // move left
            }
            else if(nums[m] < target){
                l = m + 1;
            }
            else{
                h = m - 1;
            }
        }
        return ans;
    }

    int secondO(vector<int>& nums, int target){
        int l = 0, h = nums.size() - 1;
        int ans = -1;

        while(l <= h){
            int m = l + (h - l) / 2;

            if(nums[m] == target){
                ans = m;
                l = m + 1; // move right
            }
            else if(nums[m] < target){
                l = m + 1;
            }
            else{
                h = m - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstO(nums, target);
        int second = secondO(nums, target);
        return {first, second};
    }
};

int main() {
    Solution obj;

    // Hardcoded input
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> result = obj.searchRange(nums, target);

    cout << "First Occurrence: " << result[0] << endl;
    cout << "Last Occurrence: " << result[1] << endl;

    return 0;
}