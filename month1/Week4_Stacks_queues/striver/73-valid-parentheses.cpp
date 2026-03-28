// https://leetcode.com/problems/valid-parentheses/

#include <bits/stdc++.h>
using namespace std;

// inside this I have stored all the opening bracket inside a 
// stack and whenever I am encountering any closing bracket then 
// I am comparing that closing bracket with the top of the stack 
// then if it is false then return false. after loops ends 
// if stack is empty then return true

// TC - O(n)
// SC - O(n)

class Solution {
public:
    bool compare(char open, char close){
        if(open == '{' && close == '}' || open == '(' && close == ')' ||open == '[' && close == ']')
        return true;
        return false;
    }
    bool isValid(string s) {
        int n = s.length();
        // if(n == 1) return false;
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i] == '(' ||s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }else{
                if(st.empty()) return false;
                char open = st.top();
                st.pop();
                if(!compare(open,s[i])) return false;
            }
        }
        return st.empty();
    }
};

int main() {
    Solution obj;
    string s = "{}({[]})";
    if(obj.isValid(s))
        cout << "Valid Parentheses" << endl;
    else
        cout << "Invalid Parentheses" << endl;
    return 0;
}