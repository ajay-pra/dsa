// https://takeuforward.org/plus/dsa/problems/length-of-loop-in-ll

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// helper function to find loop length
int findLengthOfLoop(ListNode* head) {

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            int count = 1;
            ListNode* temp = slow->next;

            while(temp != slow) {
                count++;
                temp = temp->next;
            }
            return count;
        }
    }

    return 0;
}

// helper function to create a loop
void createLoop(ListNode* head, int pos) {

    if(pos == 0) return;

    ListNode* temp = head;
    ListNode* loopNode = NULL;
    int count = 1;

    while(temp->next) {
        if(count == pos)
            loopNode = temp;

        temp = temp->next;
        count++;
    }

    temp->next = loopNode;
}

// helper function to insert node
ListNode* insertNode(ListNode* head, int val) {

    if(head == NULL)
        return new ListNode(val);

    ListNode* temp = head;

    while(temp->next)
        temp = temp->next;

    temp->next = new ListNode(val);
    return head;
}

int main() {

    ListNode* head = NULL;

    head = insertNode(head,1);
    head = insertNode(head,2);
    head = insertNode(head,3);
    head = insertNode(head,4);
    head = insertNode(head,5);

    // create loop at position 3
    createLoop(head,3);

    int length = findLengthOfLoop(head);

    cout << "Length of Loop: " << length << endl;

    return 0;
}