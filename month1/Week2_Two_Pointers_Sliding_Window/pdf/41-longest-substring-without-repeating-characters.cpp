// https://leetcode.com/problems/longest-substring-without-repeating-characters/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        for(int i=0;i<s.size();i++){
            unordered_map<char,int> mp;
            for(int j=i;j<s.size();j++){
                if(mp[s[j]]!=1){
                    mp[s[j]]++;
                    maxLen = max(maxLen, j-i+1);
                }
                else{
                    break;
                }
            }
        }
        return maxLen;
    }
};




class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int n = s.length();
        unordered_map<char,int> mp;
        int l = 0, r = 0;
        while(r<n){
            if(mp.find(s[r]) != mp.end()){
                l = max(l, mp[s[r]]+1);
            }
            maxLen = max(maxLen, r-l+1);
            mp[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};