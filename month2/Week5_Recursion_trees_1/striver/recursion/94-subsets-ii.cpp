// https://leetcode.com/problems/subsets-ii/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// inside this i have to use take and not take only but in this 
// case after not taking we will have to maintain a special 
// case 1 2 2 2 in this case last one will not be there so 
// we will have to use another one take condition for last index (i.e n)

// Time Complexity = O(n × 2ⁿ)


class Solution {
public:
     void func(vector<int>& nums, vector<int>& temp, int i, int n, vector<vector<int>>& ans){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        // take
        temp.push_back(nums[i]);
        func(nums, temp, i+1, n,ans);
        temp.pop_back();
        // not take
        for(int j=i+1;j<n;j++){
            if(nums[i] != nums[j]){
                func(nums, temp, j, n, ans);
                return;
            }
        }
        func(nums, temp, n, n,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=0, n = nums.size();
        vector<int> temp;
        vector<vector<int> > ans;
        func(nums, temp, i, n, ans);
        return ans;
    }
};


int main() {
    Solution sol;

    // Input array
    vector<int> nums = {1, 2, 2};

    // Get all subsets
    vector<vector<int>> result = sol.subsetsWithDup(nums);

    // Print subsets
    cout << "Subsets are:\n";
    for (auto &subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}\n";
    }

    return 0;
}