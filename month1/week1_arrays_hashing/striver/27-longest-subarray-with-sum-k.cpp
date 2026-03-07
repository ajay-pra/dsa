// https://takeuforward.org/plus/dsa/problems/longest-subarray-with-sum-k?subject=dsa&sidebar=open


#include<bits/stdc++.h>
using namespace std;

// inside this we have maintained a unordered_map in 
// which i m storing the the preSum of the input 
// array and run a loop from i=0 to size-1, 
// initilly in the starting of the loop only i am
//  checking, if sum is == to the required sum the 
// compairing its length with the max length, then 
// finding the req = sum - k; in the unordered map 
// if is there then again computing the lenth in it, 
// updating the unordered map inside a condition 
// if(mp.find(sum) == mp.end())

// TC - O(n)
// SC - O(n)

class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        unordered_map<int,int> mp;
        int len =0;
        int sum =0;
        for(int i=0;i<nums.size();i++){
            sum +=nums[i];
            if(sum == k){
                int currLen = i+1;
                len = max(len,currLen);
            }
            int req = sum-k;
            if(mp.find(req)!=mp.end()){
                len = max(len,i-mp[req]);
            }
            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
        }
        return len;
    }
};



int main(){
    vector<int> nums = {10, 5, 2, 7, 1, 9};
    int k = 15;
    Solution sol;
    int ans = sol.subarraySum(nums,k);
    cout<<ans;
    return 0;
}