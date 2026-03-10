// https://leetcode.com/problems/longest-repeating-character-replacement/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int characterReplacement(string s, int k) {
        //your code goes here
        int n = s.length();
        int maxLen = 0;
        for(int i=0;i<n;i++){
            int maxFreq = 0;
            unordered_map<int,int>mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                maxFreq = max(maxFreq, mp[s[j]]);
                int changes = (j-i+1) - maxFreq;
                if (changes <= k) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};



class Solution2 {
public:
    int characterReplacement2(string s, int k) {
        int l=0,r=0,n = s.length(), maxLen = 0, maxFreq = 0;
        unordered_map<int,int> mp;
        while(r<n){
            mp[s[r]]++;
            maxFreq = max(maxFreq, mp[s[r]]);
            while((r-l+1) - maxFreq>k){
                mp[s[l]]--;
                if(mp[s[l]] == 0){
                    mp.erase(s[l]);
                }
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};



int main() {

    string s = "AABABBA";
    int k = 1;            

    Solution obj;

    int result = obj.characterReplacement(s, k);

    cout << "Maximum length of substring after replacement: " << result << endl;

    return 0;
}