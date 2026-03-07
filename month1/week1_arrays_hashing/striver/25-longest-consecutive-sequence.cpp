// https://leetcode.com/problems/longest-consecutive-sequence/

#include<bits/stdc++.h>
using namespace std;

// inside this first of all we have stored vector element
// in unordered_set after that we traveresed on
// the unordered set and checked if it could be 
// my first element by doing mp.find(it-1) == mp.end() 
// after in the while loop we started checking for 
// the next elements by doing it = it+1 and 
// count = count +1; 

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp;
        for(int i=0;i<nums.size();i++){
            mp.insert(nums[i]);
        }
        int ans = 0, count =0;
        for (auto it : mp){
            if(mp.find(it-1) == mp.end()){
                count = 1;
                while(mp.find(it+1) != mp.end()){
                    it=it+1;
                    count = count + 1;
                }
            }
            ans = max(ans,count);
        }
        return ans;
    }
};


int main(){
    Solution sol;
    vector<int> nums = {100,4,200,1,3,2};
    int ans = sol.longestConsecutive(nums);
    cout << ans;
    return 0;
}