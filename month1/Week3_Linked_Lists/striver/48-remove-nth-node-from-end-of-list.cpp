// https://leetcode.com/problems/remove-nth-node-from-end-of-list
#include <bits/stdc++.h>
using namespace std;

// Definition of singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* sp = head;
        ListNode* fp = head;
        int cnt = 1;
        while(cnt <= n){
            fp = fp->next;
            cnt++;
        }
        if(fp == NULL) return head->next;
        while(fp->next != NULL){
            sp = sp->next;
            fp = fp->next;
        }
        ListNode* deleted = sp->next;
        sp->next = sp->next->next;
        delete deleted;
        return head;
    }
};



class Solution2 {
public:
    ListNode* removeNthFromEnd2(ListNode* head, int n) {
        ListNode* sp = head;
        ListNode* fp = head;
        ListNode* prev = nullptr;

        int count = 1;

        while(count <= n){
            fp = fp->next;
            count++;
        }

        if(fp == nullptr){
            return head->next;
        }

        while(fp){
            prev = sp;
            sp = sp->next;
            fp = fp->next;
        }

        prev->next = sp->next;

        return head;
    }
};



// Helper function to print linked list
void printList(ListNode* head) {
    while(head != nullptr) {
        cout << head->val;
        if(head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Hardcoded linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    int n = 2; // Remove 2nd node from end (should remove '4')
    Solution sol;
    head = sol.removeNthFromEnd(head, n);

    cout << "List after removing " << n << "-th node from end: ";
    printList(head);

    // Free remaining nodes
    while(head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}ṇ