// https://takeuforward.org/plus/dsa/problems/check-if-there-exists-a-subsequence-with-sum-k?subject=dsa

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void func(int n, int i, vector<int>& nums, int k, vector<int> &temp, bool &ans, int sum){
        if(sum == k){
             ans = true;
             return;
        }

        if(i==n){
            return;
        }
        // take
        // temp.push_back(nums[i]);
        func(n, i+1, nums, k, temp, ans, sum+nums[i]);
        // temp.pop_back();

        // not take
        func(n, i+1, nums, k, temp, ans, sum);
    }
    bool checkSubsequenceSum(vector<int>& nums, int k) {
         //your code goes here
         int n = nums.size();
         int i = 0;
         vector<int> temp;
         bool ans = false;
         int sum = 0;
         func(n, i, nums, k, temp, ans, sum);
         return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 2, 3, 4};  // input array
    int k = 6;                         // target sum

    bool exists = obj.checkSubsequenceSum(nums, k);

    if(exists){
        cout << "There exists a subsequence with sum = " << k << endl;
    } else {
        cout << "No subsequence has sum = " << k << endl;
    }

    return 0;
}