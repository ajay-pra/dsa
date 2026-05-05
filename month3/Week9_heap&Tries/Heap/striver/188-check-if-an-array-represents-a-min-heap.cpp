// https://takeuforward.org/plus/dsa/problems/check-if-an-array-represents-a-min-heap-?subject=dsa&approach=bfs&tab=submissions

class Solution {
public:
bool isHeap(vector<int>& nums) {
        int n = nums.size();
        for(int i = n/2 -1; i >= 0; i--) {
            int leftChildInd = 2*i + 1;
            int rightChildInd = 2*i + 2;
            if(leftChildInd < n && nums[leftChildInd] < nums[i])
                return false;
            if(rightChildInd < n && nums[rightChildInd] < nums[i])
                return false;
        }
        return true;
    }
};