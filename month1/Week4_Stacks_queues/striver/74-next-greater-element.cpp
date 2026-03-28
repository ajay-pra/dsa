// https://takeuforward.org/plus/dsa/problems/next-greater-element?subject=dsa&tab=submissions

#include <bits/stdc++.h>
using namespace std;
// Inside this I am storing the right largest 
// element in a stack and and while traversing from 
// the back comparing the element with the top of the 
// stack and acordingly doing the operation

// TC - O(N) + O(N) = O(N)
// TC - O(N)

class Solution {
public:
    vector<int> nextLargerElement(vector<int> arr) {
       int n = arr.size();
       stack<int> st;
       vector<int> ans(n);
       for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()<=arr[i]){
            st.pop();
        }
        
        if(st.empty()){
            ans[i] = -1;
        }else{
            ans[i] = st.top();
        }
        st.push(arr[i]);
       }
       return ans;
    }
};


int main() {
    Solution obj;

    vector<int> arr = {4, 5, 2, 10, 8};

    vector<int> result = obj.nextLargerElement(arr);

    for(int x : result) {
        cout << x << " ";
    }

    return 0;
}