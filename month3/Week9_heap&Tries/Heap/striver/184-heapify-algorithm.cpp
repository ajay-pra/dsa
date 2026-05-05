// https://takeuforward.org/plus/dsa/problems/heapify-algorithm?subject=dsa&approach=bfs

void heapifyUp(vector<int> &nums, int ind){
    int parentInd = (ind-1)/2;
    if(nums[parentInd]>nums[ind]){
        swap(nums[ind], nums[parentInd]);
        heapifyUp(nums, parentInd);
    }
}

void heapifyDown(vector<int> &nums, int ind){
    int leftInd = 2*ind+1;
    int rightInd = 2*ind+2;
    int smallIndex = ind;
    if(leftInd<nums.size() && nums[leftInd]<nums[smallIndex]){
        smallIndex = leftInd;
    }
    if(rightInd<nums.size() && nums[rightInd]<nums[smallIndex]){
        smallIndex = rightInd;
    }
    if(ind!=smallIndex){
        swap(nums[smallIndex], nums[ind]);
        heapifyDown(nums, smallIndex);
    }
}

class Solution {
public:
    void heapify(vector<int> &nums, int ind, int val) {
        if(nums[ind]>val){
            nums[ind] = val;
            heapifyUp(nums,ind);
        }else{
            nums[ind] = val;
            heapifyDown(nums,ind);
        }
    }
};