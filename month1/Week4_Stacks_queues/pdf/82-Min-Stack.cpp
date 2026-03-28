#include <bits/stdc++.h>
using namespace std;


class MinStack {
public:
    stack<long long> st;
    long long mini = LLONG_MAX;
    MinStack() {
        
    }
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini = val;
        }else{
            if(val>mini){
                st.push(val);
            }else{
                st.push(2LL*val - mini);
                mini = val;
            }
        }
    }
    
    void pop() {
        long long x = st.top();
        st.pop();
        if(x<mini){
            mini = 2LL*mini - x;
        }
    }
    
    int top() {
        return st.top()> mini ? st.top() : mini;
    }
    
    int getMin() {
        return mini;
    }
};



int main() {
    MinStack obj;

    // Hardcoded operations
    obj.push(5);
    obj.push(2);
    obj.push(3);
    obj.push(1);

    cout << "Current Min: " << obj.getMin() << endl;
    cout << "Top: " << obj.top() << endl;          

    obj.pop();

    cout << "After pop:\n";
    cout << "Current Min: " << obj.getMin() << endl;
    cout << "Top: " << obj.top() << endl;          

    obj.pop();

    cout << "After pop:\n";
    cout << "Current Min: " << obj.getMin() << endl;

    obj.pop();

    cout << "After pop:\n";
    cout << "Current Min: " << obj.getMin() << endl;

    return 0;
}