// https://takeuforward.org/plus/dsa/problems/implement-queue-using-linkedlist

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int d) {
        val = d;
        next = NULL;
    }
};

class LinkedListQueue {
public:
    LinkedListQueue() {
    }
    ListNode * front = nullptr;
    ListNode * back = nullptr;
    void push(int x) {
        ListNode * newNode = new ListNode(x);
        if(front == nullptr && back == nullptr){
            front = newNode;
            back = newNode;
        }else{
            back-> next = newNode;
            back = newNode;
        }

    }
    
    int pop() {
        if(front == nullptr){
            cout<<"under flow";
            return -1;
        }
        int val = front -> val;
        front = front-> next;
         if(front == nullptr) {
            back = nullptr;
        }
        return val;
    }
    
    int peek() {
        if(front == nullptr) {
            cout<<"Empty";
            return -1;
        }
        return front-> val;
    }
    
    bool isEmpty() {
        return front == nullptr;
    }
};