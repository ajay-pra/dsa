// https://takeuforward.org/plus/dsa/problems/lower-bound-?subject=dsa&category=binary-search&subcategory=fundamentals&approach=optimal&tab=submissions

#include <bits/stdc++.h>
// using namespace std;
// // This solution uses binary search to efficiently find the lower bound, 
// which is the first index where the element is greater than 
// or equal to x. Instead of scanning the array linearly, 
// we repeatedly divide the search space into halves. 
// If the middle element is smaller than x, we move 
// to the right half since the answer must lie there.
// Otherwise, we store the current index as a potential answer 
// and continue searching in the left half to check if an 
// earlier valid index exists. This ensures we always find 
// the first occurrence of an element ≥ x. If no such element exists, 
// we return n (array size). The time complexity is O(log n) 
// because the search space is halved in every step.

class Solution{
public:
    int lowerBound(vector<int> &nums, int x){
        int l=0, h=nums.size()-1;
        int mid,ans= nums.size();
        while(l<=h){
            mid = (l+h)/2;
            if(nums[mid]>=x){
                ans = mid;
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};
int main() {
    Solution obj;

    vector<int> nums = {3, 5, 8, 15, 19};
    int x = 9;

    int result = obj.lowerBound(nums, x);

    cout << "Lower Bound Index: " << result << endl;

    if(result < nums.size())
        cout << "Element at index: " << nums[result] << endl;
    else
        cout << "No element >= x found" << endl;

    return 0;
}