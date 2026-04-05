// https://takeuforward.org/plus/dsa/problems/count-all-subsequences-with-sum-k?subject=dsa

#include <bits/stdc++.h>
using namespace std;



class Solution{
    public:    
        void func(int n, int i, vector<int>& nums, int k, vector<int> &temp, int &ans, int sum){
        if(i==n){
            if(sum == k){
             ans++;
            }
            return;
        }
        // take
        // temp.push_back(nums[i]);
        func(n, i+1, nums, k, temp, ans, sum+nums[i]);
        // temp.pop_back();

        // not take
        func(n, i+1, nums, k, temp, ans, sum);
    }	
    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    	//your code goes here
        //your code goes here
         int n = nums.size();
         int i = 0;
         vector<int> temp;
         int ans = 0;
         int sum = 0;
         func(n, i, nums, k, temp, ans, sum);
         return ans;
    }
};




int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3, 4};
    int k = 6;                        
    int exists = obj.countSubsequenceWithTargetSum(nums, k);
    if(exists){
        cout << "count " << exists << endl;
    } else {
        cout << "No subsequence has sum = " << k << endl;
    }

    return 0;
}