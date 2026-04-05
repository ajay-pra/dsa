// https://leetcode.com/problems/generate-parentheses/
#include <iostream>
#include <vector>
using namespace std;

// inside this we have to have and open counter and close aounter and based on the number of them I am calling my recursive function and in base case if(open == close && open+close == 2*n) I am pushing my generated string 

class Solution {
public:
    void func(int open, int close, string s, vector<string>& ans, int n){
        if(open == close && open + close == 2 * n){
            ans.push_back(s);
            return;
        }
        if(open < n){
            func(open + 1, close, s + '(', ans, n);
        }
        if(close < open){
            func(open, close + 1, s + ')', ans, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        func(0, 0, "", ans, n);
        return ans;
    }
};

int main() {
    Solution obj;
    int n = 3;
    vector<string> result = obj.generateParenthesis(n);
    for(const string &str : result){
        cout << str << endl;
    }

    return 0;
}