// https://takeuforward.org/plus/dsa/problems/find-nth-root-of-a-number?subject=dsa&category=binary-search&subcategory=on-answers&approach=optimal


class Solution {
public:
  int NthRoot(int N, int M) {
        int l = 1, h = M;
        int ans = -1;             

        while (l <= h) {
            long long m = (l + h) / 2;  
            if (pow(m,N)== M) {
                ans = m; 
                break;   
            } else if(pow(m,N)< M){
                l = m + 1;
            } 
              else {
                h = m - 1;
            }
        }
        return ans;
    }
};



