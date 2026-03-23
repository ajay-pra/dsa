// https://leetcode.com/problems/palindrome-linked-list/description/


#include <bits/stdc++.h>
using namespace std;



Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};


class Solution {
private:
    /* Function to reverse a linked list
       using the iterative approach */
    ListNode* reverseLinkedList(ListNode* head) {
        // Initialize previous pointer as NULL
        ListNode* prev = NULL;
        
        // Initialize current pointer as head
        ListNode* curr = head;
        
        // Traverse the list until the end
        while (curr != NULL) {
            
            // Temporarily store the next node
            ListNode* nextNode = curr->next;
            
            // Reverse the link direction
            curr->next = prev;
            
            // Move 'prev' one step forward
            prev = curr;
            
            // Move 'curr' one step forward
            curr = nextNode;
        }
        
        // 'prev' will now point to the new head
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true; 
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;  
            fast = fast->next->next;  
        }
        ListNode* newHead = reverseLinkedList(slow->next);
        ListNode* first = head;  
        ListNode* second = newHead; 
        while (second != NULL) {
            if (first->val != second->val) {
                reverseLinkedList(newHead);  
                return false;
            }
            first = first->next; 
            second = second->next;  
        }
        reverseLinkedList(newHead);  
        return true;  
    }
};
