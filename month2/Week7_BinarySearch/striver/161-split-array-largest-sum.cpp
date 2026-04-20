// https://leetcode.com/problems/split-array-largest-sum/submissions/1977499323/
// https://takeuforward.org/plus/dsa/problems/book-allocation-problem?subject=dsa&approach=binary-search&sidebar=open&tab=submissions


#include <bits/stdc++.h>
using namespace std;

// This problem is solved using binary search on the answer, where we try to minimize the maximum pages assigned to any student. The search space starts from the maximum element (since one student must read at least one full book) and goes up to the total sum of all pages. For each mid value, we use a greedy helper function that simulates the allocation process by iterating through the books and assigning pages to the current student until the limit is exceeded; when it exceeds, a new student is allocated and the process continues. This helper function essentially counts how many students are required if no one is allowed to read more than mid pages. If the required students exceed the given m, it means the limit is too small, so we increase it; otherwise, we try to minimize it further. This approach efficiently finds the optimal answer in O(n log sum) time.

class Solution {
public:
    int students(vector<int> &nums, int pages){
        int student = 1;
        int pagePerStudent = 0;

        for(int i = 0; i < nums.size(); i++){
            if(pagePerStudent + nums[i] <= pages){
                pagePerStudent += nums[i];
            } else {
                student++;
                pagePerStudent = nums[i];
            }
        }
        return student;
    }

    int findPages(vector<int> &nums, int m)  {
        if(m > nums.size()) return -1;

        int l = *max_element(nums.begin(), nums.end());
        int h = accumulate(nums.begin(), nums.end(), 0);
        int ans = INT_MAX;

        while(l <= h){
            int mid = (l + h) / 2;

            int requiredStudents = students(nums, mid);

            if(requiredStudents > m){
                l = mid + 1;
            } else {
                ans = mid;
                h = mid - 1;
            }
        }
        return ans;
    }
};


class Solution2 {
public:
    int countSubArray(vector<int>& nums,int limit){
        int subArray = 1;
        int total = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]+total<=limit){
                total+=nums[i];
            }else{
                subArray++;
                total = nums[i];
            }
        }
        return subArray;
    }
    int splitArray(vector<int>& nums, int k) {
        if(k>nums.size()) return -1;
        int l = *max_element(nums.begin(), nums.end());
        int h = accumulate(nums.begin(), nums.end(), 0);
        int ans = 0;
        while(l<=h){
            int m = (l+h)/2;
            int count = countSubArray(nums, m);
            if(count>k){
                l=m+1;
            }else{
                ans = m;
                h = m-1;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {12, 34, 67, 90};
    int m = 2;

    Solution obj;
    cout << "Minimum pages: " << obj.findPages(nums, m);

    return 0;
}