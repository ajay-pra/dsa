// https://leetcode.com/problems/sum-of-subarray-minimums

#include <bits/stdc++.h>
using namespace std;

// inside this instead of going bruteforce way of generating 
// all the subarray and finding the minimum sum, I found 
// contribution of each element in the sum. for this 
// I have find nse and psee and with them only 
// I am checking the contribution of each

class Solution {
public:
    vector<int> findNSE(vector<int> arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = n;
            }else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

        vector<int> findPSEE(vector<int> arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = -1;
            }else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);
        int mod = 1e9+7;
        int sum = 0;
        for(int i=0;i<n;i++){
            int left = i - psee[i];
            int right = nse[i] - i;
            long long freq = left*right*1LL;
            int val = (freq*arr[i]*1LL) % mod;
            sum = (sum + val) % mod;
        }
        return sum;
    }
};


int main() {
    Solution obj;

    // Hardcoded input
    vector<int> arr = {3, 1, 2, 4};

    int result = obj.sumSubarrayMins(arr);

    cout << "Sum of Subarray Minimums: " << result << endl;

    return 0;
}