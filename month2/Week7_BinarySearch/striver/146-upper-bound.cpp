// https://takeuforward.org/plus/dsa/problems/upper-bound?subject=dsa&category=binary-search&subcategory=fundamentals&approach=optimal


class Solution{
public:
    int upperBound(vector<int> &nums, int x){
        int l=0, h=nums.size()-1;
        int mid,ans= nums.size();
        while(l<=h){
            mid = (l+h)/2;
            if(nums[mid]>x){
                ans = mid;
                h= mid-1;
            }else{
                l = mid+1; 
            }
        }
        return ans;  
    }
};