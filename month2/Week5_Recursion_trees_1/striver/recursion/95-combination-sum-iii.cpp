// https://leetcode.com/problems/combination-sum-iii/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// one way is by just hardcoding the aray from 1 to 9, and apply normal take and not take concept - TC = O(2^9)
class Solution {
public:
    void solve(int i, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans, int k, int n, int sum) {
        if(i == nums.size()) {
            if(temp.size() == k && sum == n) {
                ans.push_back(temp);
            }
            return;
        }

        // take nums[i]
        temp.push_back(nums[i]);
        solve(i + 1, nums, temp, ans, k, n, sum + nums[i]);
        temp.pop_back();

        // not take nums[i]
        solve(i + 1, nums, temp, ans, k, n, sum);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<int> temp;
        vector<vector<int>> ans;
        solve(0, nums, temp, ans, k, n, 0);
        return ans;
    }
};

// anothe way is by using a loop which is starting from the prev value, and take and not take condition there

class Solution {
public:
    void func(int prev, int sum, int k, int n, vector<vector<int>> &ans, vector<int> temp){
        if(sum == 0 && temp.size() == k){
            ans.push_back(temp);
            return;  
        }
        if(sum <= 0 || temp.size() > k) return; 
        for(int i = prev;i<=9;i++){
            temp.push_back(i);
            func(i+1, sum-i, k, n, ans, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int prev = 1;
        int sum = n;
        vector<vector<int>> ans;
        vector<int> temp;
        func(prev, sum, k, n, ans, temp);
        return ans;
    }
};