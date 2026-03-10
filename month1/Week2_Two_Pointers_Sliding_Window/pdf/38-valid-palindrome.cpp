// https://leetcode.com/problems/valid-palindrome/description/

#include<bits/stdc++.h>
using namespace std;

// this is a bruteforce way in which I am storing only alphanumeric in a striing then applying two pointer to check palandrome
// TC - O(n)
// SC - O(n)

class Solution {
public:
    bool isPalindrome(string s) {
        string a="";
        for(int i=0;i<s.size();i++){
            if(s[i]>='A' && s[i]<='Z' || s[i]>='a' && s[i]<='z' || s[i]>='0' && s[i]<='9'){
                a+=tolower(s[i]);
            }
        }
        cout<<a;
        bool ans = true;
        int l=0,r=a.size()-1;
        while(l<=r){
            if(a[l] != a[r]){
                ans = false;
                break;
            }
            l++;
            r--;
        }  
        return ans;        
    }
};



// another way is by removing the use of extra space just use isalnum(s[i]) to check if it is a alphanumeric or not then accordingly updating my l and r and apply teo pointer 
// TC - O(n)
// SC - O(n)


class Solution2 {
public:
    bool isPalindrome2(string s) {
        int l = 0, r = s.size() - 1;
        while(l < r) {
            while(l < r && !isalnum(s[l])) l++;
            while(l < r && !isalnum(s[r])) r--;
            if(tolower(s[l]) != tolower(s[r])) return false;
            l++;
            r--;
        }
        return true;
    }
};


int main() {
    Solution obj;

    string s = "A man, a plan, a canal: Panama";   // hardcoded input

    bool result = obj.isPalindrome(s);

    if(result)
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;

    return 0;
}