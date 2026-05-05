// https://leetcode.com/problems/reverse-linked-list/description/

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
    ListNode* reverseList(ListNode* head) {
        ListNode* left = nullptr;
        ListNode* temp = head;
        while(temp){
            ListNode* right = temp->next;
            temp->next = left;
            left = temp;
            temp=right;
        }
        return left;
    }
};



int main(){

    ListNode* head = new ListNode(1);
    head-> next = new ListNode(2);
    head-> next-> next = new ListNode(3);
    head-> next-> next-> next = new ListNode(4);
    head-> next-> next-> next-> next = new ListNode(5);

    Solution sol;

    ListNode* reversed = sol.reverseList(head);

    ListNode * temp = reversed;
    while(temp){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    return 0;
}