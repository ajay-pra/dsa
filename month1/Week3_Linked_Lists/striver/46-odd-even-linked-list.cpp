// https://leetcode.com/problems/odd-even-linked-list/


#include <bits/stdc++.h>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


//  TC - O(n)
//  SC - O(n)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* odd = nullptr;
        ListNode* oddLast = nullptr;
        ListNode* even = nullptr;
        ListNode* evenLast = nullptr;
        ListNode* temp = head;
        int count = 1;
        while(temp){
            if(count%2 == 0){
                ListNode* newNode = new ListNode(temp->val);
                if(even == nullptr){
                    even = newNode;
                    evenLast = newNode;
                }else{
                    evenLast -> next = newNode;
                    evenLast = newNode;
                }
            }else{
                ListNode* newNode = new ListNode(temp->val);
                if(odd == nullptr){
                    odd = newNode;
                    oddLast = newNode;
                }else{
                    oddLast -> next = newNode;
                    oddLast = newNode;
                }
            }
            temp = temp->next;
            count ++;
        }
        ListNode * temp2 = odd;
        while(temp2->next){
            temp2 = temp2->next;
        }
        temp2->next = even;
        return odd;
        
    }
};



class Solution2 {
public:
    ListNode* oddEvenList2(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode * odd = head;
        ListNode * even = head->next;
        ListNode * evenHead = even;
        while(even && even->next){
            odd->next = even->next;
            odd = even->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};
void printList(ListNode* head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){

    // Creating list: 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List:\n";
    printList(head);

    Solution2 obj;
    head = obj.oddEvenList2(head);

    cout << "After Odd-Even Rearrangement:\n";
    printList(head);

}