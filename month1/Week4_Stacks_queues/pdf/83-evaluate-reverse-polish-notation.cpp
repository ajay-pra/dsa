#include <bits/stdc++.h>
using namespace std;
// TC - O(N)
// SC - O(N)
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<string> st;
        for(int i=0;i<n;i++){
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
                st.push(tokens[i]);
            }else{
                int second = stoi(st.top());
                st.pop();
                int first = stoi(st.top());
                st.pop();
                if(tokens[i] == "+"){
                    st.push(to_string(first+second));
                }else if(tokens[i] == "-"){
                    st.push(to_string(first-second));
                }else if(tokens[i] == "*"){
                    st.push(to_string(first*second));
                }else{
                    st.push(to_string(first/second));
                }
            }
        }
        return stoi(st.top());
    }
};

int main() {
    Solution obj;
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int result = obj.evalRPN(tokens);
    cout << "Result: " << result << endl;
    return 0;
}