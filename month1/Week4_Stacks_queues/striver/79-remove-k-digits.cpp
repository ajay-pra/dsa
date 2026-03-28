#include <bits/stdc++.h>
using namespace std;


// Inside this first of all I have stored all the digits from left to right
// inside a stack while Poping last digits (when possible) 
// if a smaller digit is found (!st.empty() && k > 0 && st.top() > digit), 
// after that I have to check if (!st.empty() && k > 0) then accordingly 
// poping the top and reducing k, after that if stack is empty then 
// I am returning 0, then I am storing the stack into a vector then 
// trimming the zeros using while(res.size() > 0 && res.back() == '0'), 
// then reverse the vector and return the res


class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && st.top()>num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(!st.empty() && k > 0){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        string ans = "";
        while(!st.empty()){
            char top = st.top();
            ans.push_back(top);
            st.pop();
        }
        while(ans.length()>0 && ans.back() == '0'){
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        if(ans.empty()) return "0";
        return ans;
    }
};


int main() {
    Solution obj;

    string num = "1432219";
    int k = 3;
    string result = obj.removeKdigits(num, k);
    cout << "Number: " << num << endl;
    cout << "k: " << k << endl;
    cout << "Result: " << result << endl;
    return 0;
}