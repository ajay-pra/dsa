// https://leetcode.com/problems/sqrtx/

class Solution {
public:
    int mySqrt(int x) {
        int l = 0, h = x;
        int ans = 1;
        while(l<=h){
            long long m = (l+h)/2;
            if(m*m == x){
                ans = m;
                break;
            }
            else if(m*m < x){
                ans = m;
                l = m+1;
            }else{
                h = m-1;
            }
        }
        return ans;
    }
};