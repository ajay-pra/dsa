// https://takeuforward.org/plus/dsa/problems/kth-element-of-2-sorted-arrays?subject=dsa&approach=optimal&tab=submissions


class Solution {
public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        int n1 = a.size();
        int n2 = b.size();
        if(n2<n1) return kthElement(b, a, k);
        int l = max(0, k-n2), h = min(k, n1);
        while(l<=h){
            int m1 = (l+h)/2;
            int m2 = k-m1;
            int l1 = (m1>0) ? a[m1-1] : INT_MIN;
            int r1 = (m1<n1) ? a[m1] : INT_MAX;
            int l2 = (m2>0) ? b[m2-1] : INT_MIN;
            int r2 = (m2<n2) ? b[m2] : INT_MAX;
            if(l1<=r2 && l2<=r1){
                return max(l1,l2);
            }else if(l1 > r2){
                h = m1-1;
            }else{
                l = m1+1;
            }
        }
        return -1;
    }
};