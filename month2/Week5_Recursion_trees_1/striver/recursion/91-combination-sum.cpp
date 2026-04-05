// https://leetcode.com/problems/combination-sum/

#include <iostream>
#include <vector>
using namespace std;

// inside this as it is mentioned in question that i can take the same number multiple times so my take an not take logic will be slightly different 

class Solution {
public:
    void func(vector<int>& candidates, int target, vector<int> temp, int i, int n, vector<vector<int>> & ans){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(target < 0 || i == n){
            return;
        }
        // take
        temp.push_back(candidates[i]);
        func(candidates, target - candidates[i], temp, i, n, ans);

        // backtrack
        temp.pop_back();

        // not take
        func(candidates, target, temp, i + 1, n, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        func(candidates, target, temp, 0, candidates.size(), ans);
        return ans;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    // Call function
    vector<vector<int>> result = sol.combinationSum(candidates, target);

    // Print all combinations
    cout << "Combinations that sum to " << target << ":\n";
    for (auto &comb : result) {
        cout << "[ ";
        for (int x : comb) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}