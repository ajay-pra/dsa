// https://leetcode.com/problems/sum-of-subarray-ranges/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
      vector<int> findNSE(vector<int> arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
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



vector<int> findNGE(vector<int> arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<arr[i]){
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

vector<int> findPGEE(vector<int> arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<=arr[i]){
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

long long sumSubarrayMin(vector<int>& arr) {
    int n = arr.size();
    vector<int> nse = findNSE(arr);
    vector<int> psee = findPSEE(arr);

    long long sum = 0;
    for(int i=0;i<n;i++){
        long long left = i - psee[i];
        long long right = nse[i] - i;
        long long freq = left * right;
        sum += freq * arr[i];
    }
    return sum;
}

long long sumSubarrayMax(vector<int>& arr) {
    int n = arr.size();
    vector<int> nge = findNGE(arr);
    vector<int> pgee = findPGEE(arr);

    long long sum = 0;
    for(int i=0;i<n;i++){
        long long left = i - pgee[i];
        long long right = nge[i] - i;
        long long freq = left * right;
        sum += freq * arr[i];
    }
    return sum;
}

long long subArrayRanges(vector<int>& nums) {
    return sumSubarrayMax(nums) - sumSubarrayMin(nums);
}
};


int main() {
    Solution obj;

    vector<int> nums = {1, 2, 3};

    long long result = obj.subArrayRanges(nums);

    cout << "Sum of Subarray Ranges: " << result << endl;

    return 0;
}