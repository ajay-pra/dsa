// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

#include<bits/stdc++.h>
using namespace std;
// inside this firstly i have calculated total from left of
// window size k and get the total, after that as it was mentioned
// in question that i have to find total of k and i can pick from
// left or right or both left and right 

// TC - O(k)+O(k)
// SC - O(1)

class Solution{
  public:
    int maxScore(vector<int>& cardScore , int k){
        int n = cardScore.size();
        int leftSum = 0;
        for(int i = 0; i < k; i++){
            leftSum += cardScore[i];
        }
        int maxSum = leftSum;
        int rightIndex = n-1;
        int rightSum =0;
        for(int i = k-1; i >=0; i--){
            leftSum -= cardScore[i];
            rightSum += cardScore[rightIndex];
            rightIndex--;
            maxSum = max(maxSum, leftSum + rightSum);
        }
        return maxSum;
    }
};


int main(){
    vector<int> nums = {1,2,3,4,5,6,1};
    int k = 3;
    Solution sol;
    int ans = sol.maxScore(nums,k);
    cout<<ans;
    return 0;
}