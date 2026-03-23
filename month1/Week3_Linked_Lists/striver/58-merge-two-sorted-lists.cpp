#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    // Default constructor
    ListNode() {
        val = 0;
        next = nullptr;
    }

    // Value only
    ListNode(int x) {
        val = x;
        next = nullptr;
    }

    // Value + next
    ListNode(int x, ListNode* nextNode) {
        val = x;
        next = nextNode;
    }
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp = new ListNode(-1);  ;
        ListNode* ans = temp;
        while(list1 && list2){
            if(list1 -> val < list2->val){
                temp -> next = list1;
                temp = temp-> next;
                list1 = list1->next;
            }else if(list1 -> val > list2->val){
                temp -> next = list2;
                temp = temp-> next;
                list2 = list2->next;
            }else{
                temp -> next = list1;
                temp = temp-> next;
                list1 = list1->next;
                temp -> next = list2;
                temp = temp-> next;
                list2 = list2->next;
            }
           
        }
        if(list1) temp->next = list1;
        if(list2) temp->next = list2;
        return ans->next;
    }
};

ListNode* createList(vector<int> &arr) {
    if(arr.empty()) return NULL;

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
    vector<int> arr1 = {1, 2, 4};
    vector<int> arr2 = {1, 3, 4};

    ListNode* list1 = createList(arr1);
    ListNode* list2 = createList(arr2);

    Solution obj;
    ListNode* merged = obj.mergeTwoLists(list1, list2);

    cout << "Merged List:\n";
    printList(merged);

    return 0;
}