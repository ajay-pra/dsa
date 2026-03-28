#include <bits/stdc++.h>
using namespace std;

// THis is almost same as the next greater element in stack 
// here We have stored the index of the next greater element 
// and maintained an array of nge where I a storing the 
// difference (or 0) based on condition

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> nge(n);
        for(int i=n-1;i>=0;i--){
            int ele = temperatures[i];
            while(!st.empty() && temperatures[st.top()]<=ele){
                st.pop();
            }
            if(st.empty()) nge[i] = 0;
            else{
                nge[i] = st.top()-i;
            }
            st.push(i);
        }
        return nge;
    }
};

int main() {
    Solution obj;

    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};

    vector<int> result = obj.dailyTemperatures(temperatures);

    cout << "Output: ";
    for(int x : result) {
        cout << x << " ";
    }

    return 0;
}