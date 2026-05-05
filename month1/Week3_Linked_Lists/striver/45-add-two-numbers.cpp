// https://leetcode.com/problems/add-two-numbers

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() {
        val = 0;
        next = nullptr;
    }

    ListNode(int x) {
        val = x;
        next = nullptr;
    }

    ListNode(int x, ListNode *next) {
        val = x;
        this->next = next;
    }
};

class Solution {
public:

    // ----------- Brute Version (Your first logic) -----------
    ListNode* addTwoNumbersBrute(ListNode* l1, ListNode* l2) {

        ListNode* ans = nullptr;
        int carry = 0;

        while(l1 && l2){

            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            int res = sum % 10;

            ListNode* newNode = new ListNode(res);

            if(ans == nullptr){
                ans = newNode;
            }
            else{
                ListNode* temp = ans;
                while(temp->next != nullptr){
                    temp = temp->next;
                }
                temp->next = newNode;
            }

            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1){

            int sum = l1->val + carry;
            carry = sum / 10;
            int res = sum % 10;

            ListNode* newNode = new ListNode(res);

            ListNode* temp = ans;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;

            l1 = l1->next;
        }

        while(l2){

            int sum = l2->val + carry;
            carry = sum / 10;
            int res = sum % 10;

            ListNode* newNode = new ListNode(res);

            ListNode* temp = ans;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;

            l2 = l2->next;
        }

        if(carry){

            ListNode* newNode = new ListNode(carry);

            ListNode* temp = ans;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }

        return ans;
    }


    // ----------- Optimized Version (Using tail pointer) -----------
    ListNode* addTwoNumbersOptimized(ListNode* l1, ListNode* l2) {

        ListNode* ans = nullptr;
        ListNode* tail = nullptr;
        int carry = 0;

        while(l1 && l2){

            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            int res = sum % 10;

            ListNode* newNode = new ListNode(res);

            if(ans == nullptr){
                ans = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }

            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1){

            int sum = l1->val + carry;
            carry = sum / 10;
            int res = sum % 10;

            ListNode* newNode = new ListNode(res);

            tail->next = newNode;
            tail = newNode;

            l1 = l1->next;
        }

        while(l2){

            int sum = l2->val + carry;
            carry = sum / 10;
            int res = sum % 10;

            ListNode* newNode = new ListNode(res);

            tail->next = newNode;
            tail = newNode;

            l2 = l2->next;
        }

        if(carry){

            ListNode* newNode = new ListNode(carry);
            tail->next = newNode;
        }

        return ans;
    }
};



// ----------- Driver Code -----------
int main() {

    // l1 = 2 -> 4 -> 3
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // l2 = 5 -> 6 -> 4
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution obj;

    cout<<"Brute Result:\n";
    ListNode* ans1 = obj.addTwoNumbersBrute(l1,l2);

    ListNode* temp = ans1;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }

    cout<<"\nOptimized Result:\n";

    ListNode* ans2 = obj.addTwoNumbersOptimized(l1,l2);

    temp = ans2;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }

}