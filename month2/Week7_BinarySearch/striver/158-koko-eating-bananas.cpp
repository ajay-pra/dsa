// https://leetcode.com/problems/koko-eating-bananas/


class Solution {
public:
    long long sumOfD(vector<int>& piles, int d){
        long long sum = 0;
        for(int i=0; i<piles.size(); i++){
            sum += ceil((double)piles[i]/(double)d);
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, hh = *max_element(piles.begin(), piles.end());
        int ans = 0;
        while(l<=hh){
            int m = (l+hh)/2;
            if(sumOfD(piles,m)<=h){
                ans = m;
                hh = m-1;
            }else{
                l = m+1;
            }
        }
        return ans;
    }
};