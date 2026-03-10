// https://leetcode.com/problems/minimum-window-substring/

#include<bits/stdc++.h>
using namespace std;

// this is bruteforce way, inside this I have 
// used two loop, for generate all the subarrays 
// and a third loop which is just under the outer 
// loop which is used to update the unordered map 
// with the frequency of the second string (t), 
// inside the inner loop i am checking if the 
// if(mp[s[j]] > 0) then increasing the count++ 
// ( whic is used to track how many variables of 
// the string t is inside the string s), just 
// after that we are doing mp[s[j]]--; to mark 
// the visited one. if (count == t.length()) 
// then i am updating the min and sIndex and we 
// are returning the ans at the end;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int minLen = INT_MAX;
        int sIndex = -1;
        for(int i = 0; i < n; i++) {
            unordered_map<char,int> mp;
            for(char c : t) mp[c]++;
            int count = 0;
            for(int j = i; j < n; j++) {
                if(mp[s[j]] > 0) count++;
                mp[s[j]]--;
                if(count == t.length()) {
                    if(j - i + 1 < minLen) {
                        minLen = j - i + 1;
                        sIndex = i;
                    }
                    break;
                }
            }
        }

        if(sIndex == -1) return "";
        return s.substr(sIndex, minLen);
    }
};





class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int l = 0, r = 0;
        int count = 0;
        int minLen = INT_MAX;
        int start = 0;
        unordered_map<char,int> mp;
        for(char c : t){
            mp[c]++;
        }
        while(r < n){
            if(mp[s[r]] > 0) count++;
            mp[s[r]]--;
            while(count >= t.length()){
                if(r - l + 1 < minLen){
                    minLen = r - l + 1;
                    start = l;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0) count--;
                l++;
            }
            r++;
        }
        if(minLen == INT_MAX) return "";
        return s.substr(start, minLen);
    }
};



int main(){

    string s = "ADOBECODEBANC";
    string t = "ABC";

    Solution obj;
    cout << obj.minWindow(s, t);

    return 0;
}