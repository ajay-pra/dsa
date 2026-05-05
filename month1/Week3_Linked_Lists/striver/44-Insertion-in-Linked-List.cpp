// https://takeuforward.org/plus/dsa/problems/insertion-in-linked-list?subject=dsa&approach=bfs

#include <iostream>
using namespace std;

class ListNode{
public:
    int data;
    ListNode *next;

    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};

class Solution {
public:

    ListNode* insertAtHead(ListNode* &head, int X) {
        ListNode* newNode = new ListNode(X);
        newNode->next = head;
        return newNode;
    }

    ListNode* insertAtTail(ListNode* &head, int X) {
        if(head == nullptr){
            ListNode* newNode = new ListNode(X);
            return newNode;
        }

        ListNode* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }

        ListNode* newNode = new ListNode(X);
        temp->next = newNode;

        return head;
    }

    ListNode* insertAtKthPosition(ListNode* &head, int X, int K) {

        if(K == 1){
            ListNode* newNode = new ListNode(X);
            newNode->next = head;
            return newNode;
        }

        ListNode *temp = head;
        int count = 1;

        while(temp != nullptr){
            if(count == K-1){
                ListNode* newNode = new ListNode(X);
                newNode->next = temp->next;
                temp->next = newNode;
                break;
            }
            count++;
            temp = temp->next;
        }

        return head;
    }

    ListNode* insertBeforeX(ListNode* &head, int X, int val) {

        if(head == nullptr) return head;

        if(head->data == X){
            ListNode *newNode = new ListNode(val);
            newNode->next = head;
            return newNode;
        }

        ListNode *temp = head;
        ListNode *prev = nullptr;

        while(temp != nullptr && temp->data != X){
            prev = temp;
            temp = temp->next;
        }

        if(temp == nullptr) return head;

        ListNode *newNode = new ListNode(val);
        newNode->next = temp;
        prev->next = newNode;

        return head;
    }
};

void printList(ListNode* head){
    ListNode* temp = head;

    while(temp != nullptr){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){

    Solution obj;
    ListNode* head = nullptr;

    // Insert at head
    head = obj.insertAtHead(head, 10);
    head = obj.insertAtHead(head, 5);

    // Insert at tail
    head = obj.insertAtTail(head, 20);
    head = obj.insertAtTail(head, 30);

    cout << "After head and tail insertions:" << endl;
    printList(head);

    // Insert at Kth position
    head = obj.insertAtKthPosition(head, 15, 3);

    cout << "After inserting 15 at position 3:" << endl;
    printList(head);

    // Insert before X
    head = obj.insertBeforeX(head, 20, 18);

    cout << "After inserting 18 before 20:" << endl;
    printList(head);

    return 0;
}