// https://leetcode.com/problems/3sum/

#include<bits/stdc++.h>
using namespace std;

// TC - O(n log n) + O(n²)
// SC - O(1)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int l=i+1, r=n-1;
            while(l<r){
                int req = -nums[i];
                if(nums[l] + nums[r] == req){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    ans.push_back(temp);
                    l++;
                    r--;
                    while(l<r && nums[l] == nums[l-1]) l++;
                    while(l<r && nums[r] == nums[r+1]) r--;
                }
                else if(nums[l] + nums[r] < req){
                    l++;
                }else{
                    r--;
                }
            }
        }
        return ans;
    }
};



int main() {

    Solution obj;

    // Hardcoded input
    vector<int> nums = {-1,0,1,2,-1,-4};

    vector<vector<int>> result = obj.threeSum(nums);

    cout << "Triplets are:\n";

    for(auto &vec : result){
        for(auto &x : vec){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}