// https://leetcode.com/problems/reorder-list/

#include<bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

 
 class Solution {
public:
    ListNode * findMid(ListNode* head){
        ListNode* sp = head;
        ListNode* fp = head;
        while(fp && fp->next){
            sp = sp->next;
            fp = fp->next->next;
        }
        return sp;
    }

    ListNode * reverse(ListNode *midNext){
        ListNode * left = nullptr;
        ListNode * temp = midNext;
        while(temp){
            ListNode * right = temp->next;
            temp->next = left;
            left = temp;
            temp = right;
        }
        return left;
    }

    void reorderList(ListNode* head) {
        if(!head || !head->next) return;

        ListNode * mid = findMid(head);
        ListNode * reversedMidHead = reverse(mid->next);
        mid->next = nullptr;

        ListNode* temp1 = head;
        ListNode* temp2 = reversedMidHead;

        while(temp1 && temp2){
            ListNode* next1 = temp1->next;
            ListNode* next2 = temp2->next;

            temp1->next = temp2;
            temp2->next = next1;

            temp1 = next1;
            temp2 = next2;
        }
    }
};


int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    ListNode* temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    // Call reorder function
    Solution obj;
    obj.reorderList(head);

    cout << "Reordered List: ";
    temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}