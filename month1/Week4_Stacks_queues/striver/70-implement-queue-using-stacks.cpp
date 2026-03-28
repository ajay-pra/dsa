// https://leetcode.com/problems/implement-queue-using-stacks/

#include <bits/stdc++.h>
using namespace std;

// Inside this I have used two stacks s1 ans s2 
// for insertion I have used s1 to insert the 
// values and to pop i have checked if the s2 
// is empty then I am transferinf the elements 
// from s1 to s2 then poping it

class MyQueue {
public:
    stack <int> s1;
    stack <int> s2;

    MyQueue() {
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int top = s2.top();
        s2.pop();
        return top;
    }
    
    int peek() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    MyQueue* obj = new MyQueue();

    obj->push(10);
    obj->push(20);
    obj->push(30);

    cout << "Peek: " << obj->peek() << endl;   // 10

    cout << "Pop: " << obj->pop() << endl;     // 10
    cout << "Pop: " << obj->pop() << endl;     // 20

    cout << "Is Empty: " << obj->empty() << endl; // 0 (false)

    cout << "Pop: " << obj->pop() << endl;     // 30

    cout << "Is Empty: " << obj->empty() << endl; // 1 (true)

    return 0;
}