// https://leetcode.com/problems/middle-of-the-linked-list

#include <bits/stdc++.h>
using namespace std;

// Definition of singly linked list
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* sp = head;
        ListNode* fp = head;

        while(fp && fp->next){
            sp = sp->next;
            fp = fp->next->next;
        }

        return sp;
    }
};

// Function to print list
void printList(ListNode* head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){

    // Hardcoded Linked List: 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution obj;
    ListNode* middle = obj.middleNode(head);

    cout << "Middle Node Value: " << middle->val << endl;

    return 0;
}