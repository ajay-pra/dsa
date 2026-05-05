// https://leetcode.com/problems/koko-eating-bananas/submissions/1990379446/

class Solution {
public:
    long long sumOfH(vector<int>& piles, int k){
        long long sum = 0;
        for(int i=0;i<piles.size();i++){
            sum+=ceil(double(piles[i])/double(k));
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = -1;
        while(low<=high){
            int k = (low+high)/2;
            if(sumOfH(piles,k)<=h){
                high = k-1;
                ans = k;
            }else{
                low = k+1;
            }
        }
        return ans;
    }
};