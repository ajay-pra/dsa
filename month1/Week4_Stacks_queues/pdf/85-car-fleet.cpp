#include <bits/stdc++.h>
using namespace std;
// TC - O(n log n), SC - O(n)

// inside this basically I have stored my position and speed as a pair in an vector, 
// after that I have sorted that vector based on second pair element. 
// After that I have started another loop in which I am calculating time 
// to reach target for each car from the starting point and if 
// the calculated time is greater then prev time then nooffleet++ 
// and update the prev time and after that return the fleet count 

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> mp;

        for(int i = 0; i < n; i++){
            mp.push_back({position[i], speed[i]});
        }

        sort(mp.begin(), mp.end(), [](pair<int,int> a, pair<int,int> b){
            return a.first > b.first;
        });

        double currentTime = 0;
        int fleet = 0;

        for(int i = 0; i < n; i++){
            double time = double(target - mp[i].first) / double(mp[i].second);
            if(time > currentTime){
                fleet++;
                currentTime = time;
            }
        }

        return fleet;
    }
};


// inside this Instead of counting the fleet I have stored the time in a monotonic stack 
// and if my curent time is less then the st.top() (basically the previous 
// time), then continue else update the stack 

class Solution2 {
public:
    int carFleet2(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> mp;

        for(int i = 0; i < n; i++){
            mp.push_back({position[i], speed[i]});
        }

        sort(mp.begin(), mp.end(), [](pair<int,int> a, pair<int,int> b){
            return a.first > b.first;
        });

        double currentTime = 0;
        int fleet = 0;
        stack<int> st;
        for(int i = 0; i < n; i++){
            double time = double(target - mp[i].first) / double(mp[i].second);
            if(!st.empty() && time<=st.top()){
                continue;
            }     
            st.push(time);       
        }

        return st.size();
    }
};


int main() {
    Solution2 obj;

    int target = 12;
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};

    int result = obj.carFleet2(target, position, speed);

    cout << "\nTotal Car Fleets: " << result << endl;

    return 0;
}