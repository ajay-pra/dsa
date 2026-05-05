// https://leetcode.com/problems/reverse-nodes-in-k-group/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reversee(ListNode* start, int k){
        stack<int> st;
        ListNode* temp = start;

        // push k values
        for(int i = 0; i < k; i++){
            st.push(temp->val);
            temp = temp->next;
        }

        // overwrite values
        for(int i = 0; i < k; i++){
            start->val = st.top();
            st.pop();
            start = start->next;  // IMPORTANT
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;

        while(temp){
            ListNode* start = temp;
            int count = 0;

            // check if k nodes exist
            while(temp && count < k){
                temp = temp->next;
                count++;
            }

            if(count == k){
                reversee(start, k);
            }
        }

        return head;
    }
};

// Print the list
void printList(ListNode* head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    // 🔹 Manually create the linked list: 1→2→3→4→5→6→7→8
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);

    int k = 3;  // 🔹 Hardcoded k outside Solution class, but not inside

    cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.reverseKGroup(head, k);

    cout << "After k-group reverse: ";
    printList(head);

    return 0;
}