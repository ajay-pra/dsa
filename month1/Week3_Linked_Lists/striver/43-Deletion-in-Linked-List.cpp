// https://leetcode.com/problems/delete-node-in-a-linked-list/

#include <iostream>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;

    ListNode(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
public:

    // Delete Head
    ListNode* deleteHead(ListNode* &head) {
        if(head == nullptr) return head;

        ListNode* temp = head;
        head = head->next;
        delete temp;

        return head;
    }

    // Delete Tail
    ListNode* deleteTail(ListNode* &head) {
        if(head == nullptr) return head;

        if(head->next == nullptr){
            delete head;
            return nullptr;
        }

        ListNode* temp = head;

        while(temp->next->next != nullptr){
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;

        return head;
    }

    // Delete Kth Node
    ListNode* deleteKthNode(ListNode* &head, int k) {

        if(head == nullptr) return head;

        if(k == 1){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode* temp = head;
        int count = 1;

        while(temp != nullptr && count < k-1){
            temp = temp->next;
            count++;
        }

        if(temp == nullptr || temp->next == nullptr) return head;

        ListNode* deleted = temp->next;
        temp->next = temp->next->next;
        delete deleted;

        return head;
    }

    // Delete Node With Value X
    ListNode* deleteNodeWithValueX(ListNode* &head, int X) {

        if(head == nullptr) return head;

        if(head->data == X){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode* temp = head;

        while(temp->next != nullptr){

            if(temp->next->data == X){
                ListNode* deleted = temp->next;
                temp->next = temp->next->next;
                delete deleted;
                break;
            }

            temp = temp->next;
        }

        return head;
    }
};


// Print Linked List
void printList(ListNode* head){

    while(head != nullptr){
        cout << head->data << " -> ";
        head = head->next;
    }

    cout << "NULL" << endl;
}


// Driver Function
int main(){

    // Hardcoded Linked List
    // 10 -> 20 -> 30 -> 40 -> 50

    ListNode* head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next = new ListNode(50);

    Solution obj;

    cout << "Original List:\n";
    printList(head);


    // Delete Head
    head = obj.deleteHead(head);
    cout << "\nAfter Deleting Head:\n";
    printList(head);


    // Delete Tail
    head = obj.deleteTail(head);
    cout << "\nAfter Deleting Tail:\n";
    printList(head);


    // Delete 2nd Node
    head = obj.deleteKthNode(head,2);
    cout << "\nAfter Deleting 2nd Node:\n";
    printList(head);


    // Delete Node with value 40
    head = obj.deleteNodeWithValueX(head,40);
    cout << "\nAfter Deleting Node with value 40:\n";
    printList(head);

    return 0;
}