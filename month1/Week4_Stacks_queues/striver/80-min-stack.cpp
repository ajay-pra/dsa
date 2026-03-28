// https://leetcode.com/problems/min-stack/

#include <bits/stdc++.h>
using namespace std;

// ANother way could be by using two stack, first one to store the avlues and second one to store the minimum;
// Another way is by storing the encoded value if minimum changes

class MinStack {
public:
    static const int n = 1000;
    int arr[n];
    int topp = -1;
    int minimum = INT_MAX;

    MinStack() {}

    void push(int val) {
        if(topp == n - 1){
            cout << "Overflow\n";
            return;
        }
        arr[++topp] = val;

        if(val < minimum) minimum = val;
    }

    void pop() {
        if(topp == -1) {
            cout << "Underflow\n";
            return;
        }

        int popped = arr[topp--];

        if(popped == minimum) {
            minimum = INT_MAX;
            for(int i = 0; i <= topp; i++) {
                minimum = min(minimum, arr[i]);
            }
        }
    }

    int top() {
        if(topp == -1) {
            cout << "Stack Empty\n";
            return -1;
        }
        return arr[topp];
    }

    int getMin() {
        if(topp == -1) {
            cout << "Stack Empty\n";
            return -1;
        }
        return minimum;
    }
};




class MinStack2 {
public:
    stack<long long> st;
    long long minimum;

    MinStack2() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            minimum = val;
            return;
        }

        if(val >= minimum) {
            st.push(val);
        } else {
            st.push(2LL * val - minimum);
            minimum = val;
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long topp = st.top();
        st.pop(); 
        if(topp < minimum) {
            minimum = 2 * minimum - topp; 
        }
    }
    
    int top() {
        long long topp = st.top();
        if(topp >= minimum) return topp;
        else return minimum;
    }
    
    int getMin() {
        return minimum;
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