// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/


#include<bits/stdc++.h>
using namespace std;

// this below one is a bruteforce in which i am using two
// array to track all substring and i have used a hash table 
// of size 256 to track which character is used earlierif it 
// is used in substring then break form the loop
// Just one most important thing that we have to reset the hash aray on every i
// TC - O(n^2)
// SC - O(256)

class Solution{
  public:
    int longestNonRepeatingSubstring(string& s){
        //your code goes here
        int maxLen=0;
        for(int i=0;i<s.size();i++){
            vector<int> hash(256, 0);  
            for(int j=i;j<s.size();j++){
                if (hash[s[j]] == 1) break;  
                int len = j - i + 1;
                maxLen = max(maxLen, len);
                hash[s[j]] = 1;
            }
        }
        return maxLen;
    }
};



// ANother approach is using sliding window - inside
// this I have taken r=0,l=0 and started running
// while loop from r to n. and also here also I 
// am maintaining a hashmap to store the index of 
// each characoors, inside whicl loop i check if 
// the curent index charactor is already exist then 
// i update my l=max(l,mp[s[r]]+1); after that 
// I am calculating maxLen  and updating hash 
// array and increase r

// TC - O(n)
// SC - O(256)
class Solutionn {
public:
    int longestNonRepeatingSubstring2(string s) {
        int n = s.length();
        vector<int> mp(256,-1);
        int r=0,l=0,maxLen=0;
        while(r<n){
            if(mp[s[r]]!=-1){
              l=max(l,mp[s[r]]+1);
            }
            int len = r-l+1;
            maxLen = max(len,maxLen);
            mp[s[r]] = r;
            r++;
        }   
        return maxLen;
    }
};



int main(){

    string s = "abcabcbb";   // hardcoded input

    Solutionn obj;

    int result = obj.longestNonRepeatingSubstring2(s);

    cout << "result String: "  << result;
    return 0;
}