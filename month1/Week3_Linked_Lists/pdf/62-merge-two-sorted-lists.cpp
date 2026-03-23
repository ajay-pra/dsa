// https://leetcode.com/problems/merge-two-sorted-lists/description/

#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode * next;
    ListNode(){
        val = 0;
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


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp = new ListNode(-1);
        ListNode* mover = temp;
        while(list1 && list2){
            if(list1->val <= list2->val){
                mover->next = list1;
                mover = mover->next;
                list1 = list1->next;
            }else{
                mover->next = list2;
                mover = mover->next;
                list2 = list2->next;
            }
        }
        if(list1){
            mover->next = list1;
            // list1 = list1->next;
        }
        if(list2){
            mover->next = list2;
            // list2 = list2->next;
        }
        return temp->next;
    }
};


int main(){

    ListNode* head1 = new ListNode(1);
    head1-> next = new ListNode(2);
    head1-> next-> next = new ListNode(4);

    ListNode* head2 = new ListNode(1);
    head2-> next = new ListNode(3);
    head2-> next-> next = new ListNode(4);

    Solution sol;

    ListNode* merged = sol.mergeTwoLists(head1, head2);

    ListNode * temp = merged;
    while(temp){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    return 0;
}