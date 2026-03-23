#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode *child;

    ListNode() {
        val = 0;
        next = NULL;
        child = NULL;
    }

    ListNode(int data1) {
        val = data1;
        next = NULL;
        child = NULL;
    }

    ListNode(int data1, ListNode *next1, ListNode* child1) {
        val = data1;
        next = next1;
        child = child1;
    }
};

class Solution {
public:
    ListNode* flattenLinkedList(ListNode* &head) {
        ListNode* temp = head;
        vector<int> arr;

        while(temp){
            ListNode* t2 = temp;
            while(t2){
                arr.push_back(t2->val);
                t2 = t2->child;
            }
            temp = temp->next;
        }

        sort(arr.begin(), arr.end());

        ListNode* dummyNode = new ListNode(-1);
        temp = dummyNode;

        for (int i = 0; i < arr.size(); i++) {
            temp->child = new ListNode(arr[i]);
            temp = temp->child;
        }

        return dummyNode->child;
    }
};

// 🔥 Helper to print flattened list (using child pointer)
void printList(ListNode* head) {
    while(head){
        cout << head->val << " -> ";
        head = head->child;
    }
    cout << "NULL\n";
}


class Solution2 {
public:

    // 🔥 Merge two sorted child lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(l1 && l2){
            if(l1->val < l2->val){
                temp->child = l1;
                l1 = l1->child;
            }
            else{
                temp->child = l2;
                l2 = l2->child;
            }
            temp = temp->child;
        }

        if(l1) temp->child = l1;
        else temp->child = l2;

        return dummy->child;
    }

    ListNode* flattenLinkedList(ListNode* head) {
        // base case
        if(head == NULL || head->next == NULL)
            return head;

        head->next = flattenLinkedList(head->next);

        head = merge(head, head->next);

        return head;
    }
};


int main() {
    /*
        Creating this structure:

        5 -> 10 -> 19 -> 28
        |    |     |     |
        7    20    22    35
        |          |     |
        8          50    40
        |                |
        30               45
    */

    // Column 1
    ListNode* head = new ListNode(5);
    head->child = new ListNode(7);
    head->child->child = new ListNode(8);
    head->child->child->child = new ListNode(30);

    // Column 2
    head->next = new ListNode(10);
    head->next->child = new ListNode(20);

    // Column 3
    head->next->next = new ListNode(19);
    head->next->next->child = new ListNode(22);
    head->next->next->child->child = new ListNode(50);

    // Column 4
    head->next->next->next = new ListNode(28);
    head->next->next->next->child = new ListNode(35);
    head->next->next->next->child->child = new ListNode(40);
    head->next->next->next->child->child->child = new ListNode(45);

    Solution obj;
    ListNode* flat = obj.flattenLinkedList(head);

    cout << "Flattened List:\n";
    printList(flat);

    return 0;
}