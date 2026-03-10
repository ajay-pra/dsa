// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include<bits/stdc++.h>
using namespace std;

// inside this I have chosen the minLeft index 
// i the first index and started a loop from i = 1 to n, 
// then after that checking and updating the maxProfit 
// and minLeft index 

// TC - O(n)
// SC - O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minLeft = 0;
        int maxProfit = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[minLeft]){
                maxProfit = max(maxProfit, prices[i]-prices[minLeft]);
            }else{
                minLeft = i;
            }
        }
        return maxProfit;
    }
};


int main() {

    vector<int> prices = {7,1,5,3,6,4};

    Solution obj;
    int result = obj.maxProfit(prices);

    cout << result << endl;

    return 0;
}