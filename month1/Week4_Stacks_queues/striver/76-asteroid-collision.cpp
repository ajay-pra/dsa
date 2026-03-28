// https://leetcode.com/problems/asteroid-collision/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            int curr = asteroids[i];
            bool destroyed = false;
            while(!st.empty() && st.top()>0 && curr<0){
                if(st.top() < abs(curr)){
                    st.pop();
                }else if(st.top() == abs(curr)){
                    st.pop();
                    destroyed = true;
                    break;
                }else{
                    destroyed = true;
                    break;
                }
            }
            if(!destroyed) st.push(curr);
        }
        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};

int main() {
    Solution obj;

    // Hardcoded input
    vector<int> asteroids = {5, 100, -5, 20, -10, -50};

    vector<int> result = obj.asteroidCollision(asteroids);

    cout << "Result: ";
    for(int x : result){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}