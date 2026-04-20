// https://leetcode.com/problems/single-element-in-a-sorted-array/submissions/1976260544/

#include <bits/stdc++.h>
using namespace std;

// This problem is solved using binary search on index pattern. 
// In a sorted array where every element appears twice except one, 
// pairs follow a pattern: before the single element, the first 
// occurrence of a pair is at even indices, and after it, this 
// pattern breaks. We use this observation to decide whether to 
// move left or right in binary search. If the mid index follows 
// the correct pairing pattern, the single element lies on the right side; 
// otherwise, it lies on the left. This allows us to efficiently narrow down 
// the search space.

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, h = n - 1;

        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

        while (l <= h) {
            int m = (l + h) / 2;

            if (nums[m] != nums[m - 1] && nums[m] != nums[m + 1])
                return nums[m];

            if ((m % 2 == 0 && nums[m] == nums[m + 1]) ||
                (m % 2 == 1 && nums[m] == nums[m - 1])) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {1,1,2,2,3,4,4,5,5}; // answer = 3

    Solution obj;
    int ans = obj.singleNonDuplicate(nums);

    cout << "Single element: " << ans << endl;

    return 0;
}