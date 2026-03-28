// https://takeuforward.org/plus/dsa/problems/implement-queue-using-arrays?subject=dsa

#include<bits/stdc++.h>
using namespace std;

class ArrayQueue {
public:
    static const int n = 1000;
    int arr[n];
    int front = -1;
    int back = -1;

    ArrayQueue() {
    }
    
    void push(int x) {
        if(back == n-1) {
            cout<<"Overflow";
            return;
        }
        if(front == -1){
            front ++;
        }
        back ++;
        arr[back] = x;
    }
    
    int pop() {
        if(back == -1 || front>back){
            cout<<"Under Flow";
            return -1;
        }
        int frontt = arr[front];
        front ++;
        return frontt;
    }
    
    int peek() {
        if(front == -1 || front>back){
            cout<<"Underflow";
            return -1;
        }
        return arr[front];
    }
    
    bool isEmpty() {
        if(back == -1 || front> back) return true;
        return false;
    }
};

int main() {
    ArrayQueue q;

    // Push elements
    q.push(10);
    q.push(20);
    q.push(30);

    // Peek front
    cout << "Front element: " << q.peek() << endl;

    // Pop elements
    cout << "Popped: " << q.pop() << endl;
    cout << "Popped: " << q.pop() << endl;

    // Peek again
    cout << "Front element: " << q.peek() << endl;

    // Check if empty
    if(q.isEmpty())
        cout << "Queue is empty" << endl;
    else
        cout << "Queue is not empty" << endl;

    // Pop remaining
    cout << "Popped: " << q.pop() << endl;

    // Try popping from empty queue
    cout << "Popped: " << q.pop() << endl;

    return 0;
}