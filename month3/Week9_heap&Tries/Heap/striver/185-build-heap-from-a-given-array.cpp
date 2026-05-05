// https://takeuforward.org/plus/dsa/problems/build-heap-from-a-given-array?subject=dsa&category=heaps&subcategory=theory-and-implementation&approach=bfs


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void heapifyDown(vector<int> &arr, int ind) {
        int n = arr.size();
        int smallest = ind;

        int left = 2 * ind + 1;
        int right = 2 * ind + 2;

        if (left < n && arr[left] < arr[smallest])
            smallest = left;

        if (right < n && arr[right] < arr[smallest])
            smallest = right;

        if (smallest != ind) {
            swap(arr[ind], arr[smallest]);
            heapifyDown(arr, smallest);
        }
    }

    void buildMinHeap(vector<int> &nums) {
        int n = nums.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapifyDown(nums, i);
        }
    }
};

int main() {
    vector<int> nums = {10, 5, 20, 2, 4, 15};

    Solution obj;
    obj.buildMinHeap(nums);

    cout << "Min Heap: ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}