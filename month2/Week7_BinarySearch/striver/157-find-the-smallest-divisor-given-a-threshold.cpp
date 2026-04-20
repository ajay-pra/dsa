// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

#include <bits/stdc++.h>
using namespace std;

// This problem uses binary search on the answer to find the smallest divisor d such that the sum of ceil(nums[i] / d) for all elements is less than or equal to the given threshold. The search space lies between 1 and the maximum element in the array. For each mid value (candidate divisor), we compute the sum using the helper function; if the sum is within the threshold, it means the divisor is valid and we try to minimize it further by searching the left half, otherwise we move to the right half to try a larger divisor. This works because the function is monotonic—as the divisor increases, the overall sum decreases—making binary search applicable. The time complexity is O(n log(max(nums))).

class Solution {
public:
    int sumByD(vector<int>& nums, int d){
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans += ceil((double)nums[i] / (double)d);
        }
        return ans;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int h = *max_element(nums.begin(), nums.end());
        int ans = INT_MAX;

        while(l <= h){
            int m = (l + h) / 2;

            if(sumByD(nums, m) <= threshold){
                ans = min(ans, m);
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;

    int result = obj.smallestDivisor(nums, threshold);
    cout << "Smallest Divisor: " << result << endl;

    return 0;
}