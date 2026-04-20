// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

#include <bits/stdc++.h>
using namespace std;

// This problem is solved using Binary Search on the answer. Instead of checking every day sequentially, we search between the minimum and maximum bloom days. For a given day (mid), we check if it’s possible to make m bouquets where each bouquet requires k consecutive flowers that have bloomed by that day. The helper function counts consecutive flowers and calculates how many bouquets can be formed. If it's possible, we try to minimize the number of days by moving left; otherwise, we move right. This efficiently finds the minimum day required.

class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int mid, int m, int k){
        int count = 0; 
        int bd = 0;

        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= mid){
                count++;
            }else{
                bd += count / k;
                count = 0;
            }
        }
        bd += count / k; // last segment

        return bd >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m * k > bloomDay.size()) return -1;

        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int h = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = 0;

        while(l <= h){
            int mid = (l + h) / 2;

            if(isPossible(bloomDay, mid, m, k)){
                ans = mid;
                h = mid - 1; // try smaller days
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3, k = 1;

    int result = obj.minDays(bloomDay, m, k);
    cout << "Minimum days required: " << result << endl;

    return 0;
}