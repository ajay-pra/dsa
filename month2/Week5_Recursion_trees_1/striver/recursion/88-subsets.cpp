// https://leetcode.com/problems/subsets/

#include <bits/stdc++.h>
using namespace std;

// inside this I am using take and not take concept, 
// basically the when taking then i have to put that index 
// value to a temp vector and remove that whil backtracking 
// and while not take just move forward bu updating the index.
// Also please take care while passing the temp/arr

// TC = O(n) (for copying the arr to ans) * O(2^n) (for taking and not taking)
// SC = O(n) (auxilary stack space) * O(2^n) (for output)

class Solution {
public:
    void func(vector<vector<int>> &ans, vector<int> &arr, vector<int>& nums, int index, int n){
        if(index == n){
            ans.push_back(arr);
            return;
        }

        // take
        arr.push_back(nums[index]);
        func(ans, arr, nums, index+1, n);

        // backtrack
        arr.pop_back();

        // not take
        func(ans, arr, nums, index+1, n);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;
        int n = nums.size();
        func(ans, arr, nums, 0, n);
        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 2, 3};  // input

    vector<vector<int>> result = obj.subsets(nums);

    cout << "Power Set:\n";
    for(auto subset : result) {
        cout << "{ ";
        for(auto x : subset) {
            cout << x << " ";
        }
        cout << "}\n";
    }

    return 0;
}