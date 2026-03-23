#include <bits/stdc++.h>
using namespace std;

/*
Definition of singly linked list:
*/
class ListNode{
  public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* &head) {

        ListNode* zero = new ListNode(-1);
        ListNode* one = new ListNode(-1);
        ListNode* two = new ListNode(-1);

        ListNode* zeroHead = zero;
        ListNode* oneHead = one;
        ListNode* twoHead = two;

        ListNode* temp = head;

        while(temp){
            if(temp->data == 0){
                zero->next = temp;
                zero = temp;
            }

            if(temp->data == 1){
                one->next = temp;
                one = temp;
            }

            if(temp->data == 2){
                two->next = temp;
                two = temp;
            }

            temp = temp->next;
        }

        zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
        one->next = twoHead->next;
        two->next = NULL;

        return zeroHead->next;
    }
};

void printList(ListNode* head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){

    // Hardcoded linked list: 1 -> 0 -> 2 -> 1 -> 0 -> 2
    ListNode* head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(0);
    head->next->next->next->next->next = new ListNode(2);

    cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.sortList(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}