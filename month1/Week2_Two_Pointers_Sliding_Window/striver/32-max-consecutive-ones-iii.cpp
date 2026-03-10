// https://leetcode.com/problems/max-consecutive-ones-iii


#include<bits/stdc++.h>
using namespace std;

// bruteforce way
// instead of finding the maximum number of consecutive 1's
//  in the array if you can flip at most k 0's. 
//  we have find maxLength of the array in which at 
//  max k zeros is there.
// TC - O(n^2)
// SC - O(1)

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen=0;
        for(int i=0;i<nums.size();i++){
            int zeros = 0;
            for(int j=i;j<nums.size();j++){
                if(nums[j] == 0) zeros++;
                if(zeros<=k){
                    int len = j-i+1;
                    maxLen = max(len,maxLen);
                }
            }
        }
        return maxLen;
    }
};


// Another way is by using two pointers

// inside this we have used two pointer l and r 
// which are initially  l = 0, r = 0; ran a while 
// loop while(r < n) if nums[r] == 0 updated zeroes 
// and if zeros > k then pdated l accordingly inside 
// that only calculated maxLen and returned maxLen as 
// the ans


class Solution2 {
public:
    int longestOnes2(vector<int>& nums, int k) {
        int maxLen=0, l=0,r=0, n = nums.size(), zero = 0;
        while(r<n){
            if(nums[r]==0) zero++;
            while(zero>k){
                if(nums[l] == 0){
                    zero--;
                }
                l++;
            }
            int len = r - l + 1;
            maxLen = max(maxLen, len);
            r++; 
        }
        return maxLen;
    }
};