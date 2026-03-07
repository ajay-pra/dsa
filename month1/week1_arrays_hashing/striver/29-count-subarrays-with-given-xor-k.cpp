// https://takeuforward.org/plus/dsa/problems/count-subarrays-with-given-xor-k?subject=dsa&tab=submissions&approach=optimal


#include<bits/stdc++.h>
using namespace std;

// this is same as the subarray with sum k 

class Solution {
public:
    int subarraysXor(vector<int> &nums, int k) {
        unordered_map<int,int> mp;
        int count = 0;
        int xr = 0;
        for(int i = 0; i < nums.size(); i++){
            xr ^= nums[i];
            if(xr == k) count++;
            int req = xr ^ k;
            if(mp.find(req) != mp.end()){
                count += mp[req];
            }
            mp[xr]++;
        }

        return count;
    }
};


int main(){
    vector<int> nums = {4, 2, 2, 6, 4};
    int k = 6;
    Solution sol;
    int ans = sol.subarraysXor(nums,k);
    cout<<ans;
    return 0;
}