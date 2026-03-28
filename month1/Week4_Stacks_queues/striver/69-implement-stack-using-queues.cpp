// https://leetcode.com/problems/implement-stack-using-queues/


//  Inside this for insertion I have used a queue only
//  but at the time of insertion of any new element I am 
//  just rotating the rest que to push it to the right of 
//  the inserted element


#include<bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int s = q.size();
        for(int i=0;i<s-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int frontt = q.front();
        q.pop();
        return frontt;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack st;

    // Push elements
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    // Top element
    cout << "Top: " << st.top() << endl;

    // Pop elements
    cout << "Popped: " << st.pop() << endl;
    cout << "Popped: " << st.pop() << endl;

    // Top again
    cout << "Top: " << st.top() << endl;

    // Check empty
    if(st.empty())
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;

    // Pop remaining
    cout << "Popped: " << st.pop() << endl;
    cout << "Popped: " << st.pop() << endl;

    // Check empty again
    if(st.empty())
        cout << "Stack is empty" << endl;

    return 0;
}