#include <bits/stdc++.h>
#include <vector>
using namespace std;


class Solution {
public:

        void func(vector<int>& candidates, int target, int i, vector<vector<int>> &ans,vector<int> arr){
        if(target ==0) {
            ans.push_back(arr);
            return;
        }
        if(target < 0 || i == candidates.size()) return; 

        // take it 
        arr.push_back(candidates[i]);
        func(candidates,target-candidates[i],i+1,ans,arr);
        arr.pop_back();

        // not take it
        for(int j=i+1;j<candidates.size();j++){
            if(candidates[i]!=candidates[j]){
             func(candidates,target,j,ans,arr);
             break;
            }
        }
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        sort(candidates.begin(), candidates.end());
        func(candidates,target,0,ans,arr);
        return ans;
    }
};



int main() {
    Solution sol;

    // Example input
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 7;

    // Call function
    vector<vector<int>> result = sol.combinationSum2(candidates, target);

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