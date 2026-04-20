// https://leetcode.com/problems/binary-search/


#include <bits/stdc++.h>
using namespace std;

// TC - O(log n)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;

        while (l <= h) {
            int m = l + (h - l) / 2;

            if (nums[m] == target) {
                return m;
            }
            else if (nums[m] > target) {
                h = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11, 13};
    int target = 7;
    Solution obj;
    int result = obj.search(nums, target);
    cout << result << endl;
    return 0;
}