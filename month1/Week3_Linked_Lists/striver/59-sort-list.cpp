// https://leetcode.com/problems/sort-list/



#include <bits/stdc++.h>
using namespace std;

// 🔹 Definition
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

    ListNode(int x, ListNode *nextNode) {
        val = x;
        next = nextNode;
    }
};

class Solution {
public:
    ListNode* mergeTwoSortedLinkedLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next; 
        }

        if (list1 != nullptr) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }
        return dummyNode->next;
    }

    ListNode* findMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* middle = findMiddle(head);
        
        ListNode* right = middle->next;
        middle->next = nullptr;
        ListNode* left = head;
        
        left = sortList(left);
        right = sortList(right);
        
        return mergeTwoSortedLinkedLists(left, right);
    }
};

ListNode* createList(vector<int>& arr) {
    if(arr.empty()) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for(int i = 1; i < arr.size(); i++){
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

void printList(ListNode* head) {
    while(head){
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    vector<int> arr = {4, 2, 1, 3, 5};

    ListNode* head = createList(arr);

    cout << "Original List:\n";
    printList(head);

    Solution obj;
    head = obj.sortList(head);

    cout << "Sorted List:\n";
    printList(head);

    return 0;
}