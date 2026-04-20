// https://takeuforward.org/plus/dsa/problems/aggressive-cows?subject=dsa&approach=binary-search&tab=submissions

#include <bits/stdc++.h>
using namespace std;

// The problem is solved using binary search on the answer, where we try to maximize the minimum distance between cows. First, we sort the stall positions so that distances can be calculated in order. Then we define a search space for the answer: the minimum possible distance is 1 and the maximum is the difference between the last and first stall. For each mid value in this range, we check using a greedy approach (isPossible) whether we can place all k cows such that the distance between any two placed cows is at least mid. If it is possible, we store this distance and try to increase it (move right), otherwise we reduce the distance (move left). This works because the feasibility of placing cows is monotonic with respect to distance, allowing efficient binary search to find the optimal maximum minimum distance.

class Solution {
public:
    bool isPossible(vector<int> &nums, int distance, int k){
        int prev = nums[0];
        int count = 0;
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] - prev >= distance){
                count++;
                prev = nums[i];
            }
            if(count + 1 >= k) return true;
        }
        return false;
    }

    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size() - 1;
        int l = 1;
        int h = nums[n] - nums[0];
        int ans = 0;
        
        while(l <= h){
            int m = (l + h) / 2;
            
            if(isPossible(nums, m, k)){
                ans = m;
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> stalls = {1, 2, 4, 8, 9};
    int k = 3;

    Solution obj;
    cout << "Maximum minimum distance: " 
         << obj.aggressiveCows(stalls, k);

    return 0;
}