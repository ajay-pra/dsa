// https://leetcode.com/problems/subarray-sum-equals-k/

#include<bits/stdc++.h>
using namespace std;
//  inside this we are using a hash table to store the
//  frequency of the prefixsum at each index
//   and findng the count in hash table of the 
//   required element
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int count =0;
        int sum =0;
        for(int i=0;i<nums.size();i++){
            sum+= nums[i];
            if(sum == k) count++;
            int req=sum-k;
            if(mp.find(req)!=mp.end()){
                count+=mp[req];
            }
            mp[sum]++;
        }
        return count;
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