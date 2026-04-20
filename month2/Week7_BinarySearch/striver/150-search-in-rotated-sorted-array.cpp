// https://leetcode.com/problems/search-in-rotated-sorted-array/


#include <bits/stdc++.h>
using namespace std;

// This approach uses binary search on a rotated sorted array. At each step, we find the middle element and check which half is sorted (left or right). Then we see if the target lies in that sorted half and discard the other half, reducing the search space.

// Time Complexity: O(log n)
// Space Complexity: O(1)

// The = condition is important to include boundary elements like nums[l] or nums[h]. Without it, the target at the edges might be skipped, giving wrong results.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;

        while(l <= h){
            int m = l + (h - l) / 2;

            if(nums[m] == target) return m;

            // right half sorted
            if(nums[m] <= nums[h]){
                if(nums[m] < target && target <= nums[h]){
                    l = m + 1;
                } else {
                    h = m - 1;
                }
            }
            // left half sorted
            else{
                if(nums[l] <= target && target < nums[m]){
                    h = m - 1;
                } else {
                    l = m + 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution obj;

    // Hardcoded input
    vector<int> nums = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int target = 1;

    int index = obj.search(nums, target);

    if(index == -1)
        cout << "Target not found\n";
    else
        cout << "Target found at index: " << index << endl;

    return 0;
}