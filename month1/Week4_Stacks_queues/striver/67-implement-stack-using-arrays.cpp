// https://takeuforward.org/plus/dsa/problems/implement-stack-using-arrays?subject=dsa&approach=bfs

#include<bits/stdc++.h>
using namespace std;

class ArrayStack {
public:
    int n = 1000;
    int arr[1000];
    int front = -1;

    ArrayStack() {
    }
    
    void push(int x) {
        if(front == 999) {
            cout<<"Overflow"<<endl;
            return;
        }
        front ++;
        arr[front] = x;
    }
    
    int pop() {
        if(front == -1){
            cout<< "Underflow"<<endl;
            return -1;
        }
        int frontp = arr[front];
        front--;
        return frontp;
    }
    
    int top() {
        if(front == -1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return arr[front];
    }
    
    bool isEmpty() {
        return front == -1;
    }
};

int main() {
    ArrayStack st;

    // Push elements
    st.push(10);
    st.push(20);
    st.push(30);

    // Top element
    cout << "Top element: " << st.top() << endl;

    // Pop elements
    cout << "Popped: " << st.pop() << endl;
    cout << "Popped: " << st.pop() << endl;

    // Check top again
    cout << "Top element: " << st.top() << endl;

    // Check if empty
    if(st.isEmpty())
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;

    // Pop remaining
    cout << "Popped: " << st.pop() << endl;

    // Try popping from empty stack
    cout << "Popped: " << st.pop() << endl;

    return 0;
}