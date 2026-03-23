// https://leetcode.com/problems/rotate-list/

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }
        ListNode * sp = head;
        ListNode * fp = head;
        ListNode * temp = head;
        int len = 1;
        while(temp->next!=nullptr){
            len++;
            temp= temp->next;
        }
        k=k%len;
        if(k == 0) return head;
        int count = 1;
        while(count <= k && fp!= nullptr){
            fp = fp->next;
            count++;
        }
        ListNode * prev = nullptr;
        while(fp != nullptr){
            prev = sp;
            sp=sp->next;
            fp=fp->next;
        }
        // temp = sp;
        // while(temp && temp->next){
        //     temp=temp->next;
        // }
        temp->next = head;
        prev->next = nullptr;
        return sp;
    }
};

ListNode* createList(vector<int> &arr) {
    if(arr.size() == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for(int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

void printList(ListNode* head) {
    while(head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}


int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;

    ListNode* head = createList(arr);

    cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.rotateRight(head, k);

    cout << "Rotated List: ";
    printList(head);

    return 0;
}