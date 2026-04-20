// https://takeuforward.org/plus/dsa/problems/floor-and-ceil-in-sorted-array?subject=dsa&category=binary-search&subcategory=logic-building&approach=optimal&tab=submissions


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getFloor(vector<int> nums, int x){
        int ans = -1;
        int l = 0, h = nums.size()-1;

        while(l <= h){
            int m = (l + h) / 2;

            if(nums[m] == x) return nums[m];

            if(nums[m] < x){
                ans = nums[m];
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        return ans;
    }

    int getCeil(vector<int> nums, int x){
        int ans = -1;
        int l = 0, h = nums.size()-1;

        while(l <= h){
            int m = (l + h) / 2;

            if(nums[m] == x) return nums[m];

            if(nums[m] < x){
                l = m + 1;
            } else {
                ans = nums[m];
                h = m - 1;
            }
        }
        return ans;
    }

    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int floor = getFloor(nums, x);
        int ceil = getCeil(nums, x);
        return {floor, ceil};
    }
};

int main() {
    Solution obj;

    // 🔹 Hardcoded input
    vector<int> nums = {1, 2, 4, 6, 8, 10};
    int x = 5;

    vector<int> ans = obj.getFloorAndCeil(nums, x);

    cout << "Floor: " << ans[0] << endl;
    cout << "Ceil: " << ans[1] << endl;

    return 0;
}