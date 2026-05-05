// https://takeuforward.org/plus/dsa/problems/convert-min-heap-to-max-heap?subject=dsa&approach=bfs
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void heapifyDown(vector<int> &arr, int ind) {
        int n = arr.size();
        int largestInd = ind; 
        int leftChildInd = 2*ind + 1, rightChildInd = 2*ind + 2;

        if(leftChildInd < n && arr[leftChildInd] > arr[largestInd]) 
            largestInd = leftChildInd;

        if(rightChildInd < n && arr[rightChildInd] > arr[largestInd]) 
            largestInd = rightChildInd;

        if(largestInd != ind) {
            swap(arr[largestInd], arr[ind]);
            heapifyDown(arr, largestInd);
        }
    }

    vector<int> minToMaxHeap(vector<int> nums) {
        int n = nums.size();
        for(int i = n/2 - 1; i >= 0; i--) {
            heapifyDown(nums, i);
        }
        return nums;
    }
};

int main() {
    // 🔹 Hardcoded min heap input
    vector<int> nums = {1, 3, 5, 7, 9, 6};

    Solution obj;
    vector<int> result = obj.minToMaxHeap(nums);

    cout << "Max Heap: ";
    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}