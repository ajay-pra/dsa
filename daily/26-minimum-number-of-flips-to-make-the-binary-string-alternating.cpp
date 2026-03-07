// https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(string s) {

        int n = s.size();

        // Step 1: Double the string to simulate rotations
        // Any rotation of length n will appear as a substring in s+s
        string t = s + s;

        // Step 2: Create two alternating patterns of length 2*n
        // alt1 = 010101010...
        // alt2 = 101010101...
        string alt1 = "", alt2 = "";

        for(int i = 0; i < 2*n; i++){
            if(i % 2 == 0){
                alt1 += '0';
                alt2 += '1';
            }
            else{
                alt1 += '1';
                alt2 += '0';
            }
        }

        // diff1 → mismatches with pattern alt1
        // diff2 → mismatches with pattern alt2
        int diff1 = 0, diff2 = 0;

        // answer = minimum flips required
        int ans = INT_MAX;

        // left pointer for sliding window
        int l = 0;

        // Step 3: Sliding window across the doubled string
        for(int r = 0; r < 2*n; r++){

            // Check mismatch with pattern alt1
            if(t[r] != alt1[r]) diff1++;

            // Check mismatch with pattern alt2
            if(t[r] != alt2[r]) diff2++;

            // If window size exceeds n, shrink from left
            if(r - l + 1 > n){

                // Remove the contribution of the left element
                if(t[l] != alt1[l]) diff1--;
                if(t[l] != alt2[l]) diff2--;

                l++; // move left pointer
            }

            // If window size is exactly n
            // it represents one rotation of the original string
            if(r - l + 1 == n){

                // update minimum flips
                ans = min(ans, min(diff1, diff2));
            }
        }

        return ans;
    }
};



int main(){

    string s = "01001001101";

    Solution obj;

    cout << obj.minFlips(s);

    return 0;
}