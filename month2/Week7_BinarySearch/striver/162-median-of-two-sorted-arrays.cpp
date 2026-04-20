// https://leetcode.com/problems/median-of-two-sorted-arrays/description/

#include <bits/stdc++.h>
using namespace std;

// This problem is solved using binary search on the smaller array to efficiently find the correct partition between two sorted arrays. The idea is to divide both arrays such that the left half contains (n1 + n2 + 1) / 2 elements and all elements in the left half are less than or equal to those in the right half. We pick a partition index mid1 in the first array and compute the corresponding partition mid2 in the second array. Using boundary values (INT_MIN and INT_MAX), we handle edge cases when partitions reach array limits. If the partition is valid (l1 <= r2 and l2 <= r1), we compute the median based on total length (odd or even). Otherwise, we adjust the binary search range. This approach runs in O(log(min(n1, n2))) time and is optimal.

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int n = n1 + n2;
        int left = (n + 1) / 2;

        int l = 0, h = n1;

        while(l <= h){
            int mid1 = (l + h) / 2;
            int mid2 = left - mid1;

            int l1 = (mid1 > 0) ? nums1[mid1 - 1] : INT_MIN;
            int r1 = (mid1 < n1) ? nums1[mid1] : INT_MAX;

            int l2 = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN;
            int r2 = (mid2 < n2) ? nums2[mid2] : INT_MAX;

            if(l1 <= r2 && l2 <= r1){
                if(n % 2 == 1) return max(l1, l2);
                else return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else if(l1 > r2){
                h = mid1 - 1;
            }
            else{
                l = mid1 + 1;
            }
        }
        return 0;
    }
};

int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    Solution obj;
    double median = obj.findMedianSortedArrays(nums1, nums2);

    cout << "Median is: " << median << endl;

    return 0;
}