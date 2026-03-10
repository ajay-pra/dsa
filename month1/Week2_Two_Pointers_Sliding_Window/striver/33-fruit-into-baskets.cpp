// https://leetcode.com/problems/fruit-into-baskets/description/


#include<bits/stdc++.h>
using namespace std;

// brute force approach
// inside this I have a set which take track of the unique elements 
// of the window i am visiting and used two loop in which i am 
// considering all the subset and checking if the size of the subeset is less then 2, then I am counting the maxLength

class Solution{
  public:
    int totalFruits(vector<int>& fruits){
        //your code goes here
        int n = fruits.size();
        int maxLen=0;
        for(int i=0;i<n;i++){
            unordered_set<int> set; 
            for(int j=i;j<n;j++){
                set.insert(fruits[j]);
                if(set.size()<=2){
                    int len = j - i + 1;
                    maxLen = max(maxLen, len);
                }
            }
        }
        return maxLen;
    }
};


// inside this I have used unordered_map<int,int>mp and 
// two pointer which are l=0,r=0 and run a while loop r<n, 
// and increasing thefrequency of the element in map if mp.size>2
// then I am increasing the left side pointer and reducing the left 
// side frequency and if frequency is 0 the erase it
//  TC - O(n)
//  SC - O(1)

class Solution2{
  public:
    int totalFruit2(vector<int>& fruits){
        //your code goes here
        int l=0,r=0,maxLen=0,n=fruits.size();
        unordered_map<int,int>mp;
        while(r<n){
            mp[fruits[r]]++;
            while(mp.size()>2) {
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0) mp.erase(fruits[l]);
                l++;
            }
            int len = r-l+1;
            maxLen = max(maxLen,len);
            r++;
        }
        return maxLen;
    }
};


int main() {

    // Hardcoded input
    vector<int> fruits = {1, 2, 1, 2, 3, 2, 2};

    Solution2 obj;

    int result = obj.totalFruit2(fruits);

    cout << result << endl;

    return 0;
}