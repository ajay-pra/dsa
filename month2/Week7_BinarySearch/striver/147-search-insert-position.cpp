// https://leetcode.com/problems/search-insert-position/

#include <bits/stdc++.h>
using namespace std;

// This solution uses binary search to either find the 
// target element or determine the position where it 
// should be inserted in a sorted array. We maintain 
// two pointers (l and h) and repeatedly check the 
// middle element. If the target is found, we return 
// its index immediately. If the middle element is 
// smaller than the target, we move to the right half; 
// otherwise, we move to the left half. When the loop 
// ends (i.e., l > h), the pointer l naturally points 
// to the correct position where the target should be 
// inserted to maintain sorted order. This works because 
// binary search progressively narrows down the valid 
// insertion range. The time complexity is O(log n).

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;

        while(l <= h){
            int m = (l + h) / 2;

            if(nums[m] == target) return m;
            else if(nums[m] < target){
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        return l;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {3, 5, 8, 15, 19};
    int target = 9;

    int index = obj.searchInsert(nums, target);

    cout << "Insert/Search Position: " << index << endl;

    return 0;
}