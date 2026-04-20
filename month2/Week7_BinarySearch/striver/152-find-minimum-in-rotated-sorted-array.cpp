// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/


#include <bits/stdc++.h>
using namespace std;

// This solution uses binary search on a rotated sorted array to find the minimum element. At each step, we check whether the right half is sorted (nums[m] < nums[h]). If it is, then the minimum lies in the left part including m, so we update the answer and move left. Otherwise, the left half is sorted, and the minimum must be in the right half, so we update the answer with nums[l] and move right. This way, we reduce the search space by half in each step.

// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int h = nums.size() - 1;
        int ans = INT_MAX;

        while(l <= h){
            int m = l + (h - l) / 2;

            // right half sorted
            if(nums[m] < nums[h]){
                ans = min(ans, nums[m]);
                h = m - 1;
            }
            else{
                ans = min(ans, nums[l]);
                l = m + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;

    // Hardcoded input
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    int minimum = obj.findMin(nums);

    cout << "Minimum element: " << minimum << endl;

    return 0;
}