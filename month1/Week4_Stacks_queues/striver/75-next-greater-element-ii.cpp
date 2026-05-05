// https://leetcode.com/problems/next-greater-element-ii/

#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=2*n -1; i >= 0;i--){
            int currInd = i%n;
            while(!st.empty() && st.top()<=nums[currInd]){
                st.pop();
            }
            if(i<n){
                if(st.empty()){
                    ans[i] = -1;
                }else{
                    ans[i] = st.top();
                }
            }
            st.push(nums[currInd]);
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