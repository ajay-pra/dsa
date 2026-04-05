// https://takeuforward.org/plus/dsa/problems/subsets-i
#include <bits/stdc++.h>
#include <vector>
using namespace std;


class Solution {
  public:
    void func(vector<int>& nums, vector<int>& ans, int i, int n, int sum){
        if(i==n){
            ans.push_back(sum);
            return;
        }
        // take
        func(nums, ans, i+1, n, sum+nums[i]);
        // not take
        func(nums, ans, i+1, n, sum);
    }
    vector<int> subsetSums(vector<int>& nums) {
        //your code goes here
        int i=0, n = nums.size(), sum =0;
        vector<int> ans;
        func(nums, ans, i, n, sum);
        return ans;
    }
};



int main() {
    Solution sol;

    vector<int> nums = {2, 3};

    vector<int> result = sol.subsetSums(nums);

    cout << "Subset sums:\n";
    for (int sum : result) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}