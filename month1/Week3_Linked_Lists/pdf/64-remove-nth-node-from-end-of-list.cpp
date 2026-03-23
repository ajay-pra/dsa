// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * prev = nullptr;
        ListNode * sp = head;
        ListNode * fp = head;
        int count = 1;
        while(count <= n){
            fp=fp->next;
            count++;
        }
        if(fp == nullptr) return head->next;
        while(fp){
            prev = sp;
            sp = sp->next;
            fp = fp->next;
        }
        prev->next = sp->next;
        delete sp;
        return head;
    }
};


int main(){

    ListNode* head = new ListNode(1);
    head-> next = new ListNode(2);
    head-> next-> next = new ListNode(3);
    head-> next-> next-> next = new ListNode(4);
    head-> next-> next-> next-> next = new ListNode(5);

    Solution sol;

    ListNode* reversed = sol.removeNthFromEnd(head, 5);

    ListNode * temp = reversed;
    while(temp){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
    return 0;
}