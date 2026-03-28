// https://takeuforward.org/plus/dsa/problems/implement-stack-using-linkedlist?

// TC- O(1)
struct ListNode{
    int val;
    ListNode * next;
    ListNode(){
        val = -1;
        next = nullptr;
    }
    ListNode(int x){
        val = x;
        next = nullptr;
    }
    ListNode(int x, ListNode * nextt){
        val = x;
        next = nextt;
    }
};

class LinkedListStack {
public:
    LinkedListStack() {

    }
    ListNode * head = nullptr;
    
    void push(int x) {
        ListNode * newNode = new ListNode(x);
        newNode -> next = head;
        head = newNode;
    }
    
    int pop() {
        if(head == nullptr) {
            cout<<"Underflow";
            return -1;
        }
        int val = head -> val;
        ListNode * temp = head;
        head = head->next;
        delete temp;
        return val;
    }
    
    int top() {
        if(head == nullptr) {
            cout << "Empty Stack";
            return -1;
        }
        return head->val;
    }
    
    bool isEmpty() {
        return head == nullptr;
    }
};