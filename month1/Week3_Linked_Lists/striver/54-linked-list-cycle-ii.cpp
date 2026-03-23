// https://leetcode.com/problems/linked-list-cycle-ii/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp = head;
        unordered_map<ListNode *, int> mp;
        int count = 1;

        while(temp){
            if(mp.find(temp) != mp.end()){
                return temp;
            }
            mp[temp] = count;
            count++;
            temp = temp->next;
        }
        return nullptr;
    }
};



// Another way is by using turtois and hair algorithm
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fp = head;
        ListNode* sp = head;
        while(fp && fp->next){
            sp = sp-> next;
            fp = fp->next->next;
            if(sp == fp){
                sp = head;
                while(sp != fp){
                    sp=sp->next;
                    fp=fp->next;
                }
                return sp;
            }
        }
        return nullptr;
    }
};


int main() {
    
    // Creating nodes
    ListNode* head = new ListNode(3);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(0);
    ListNode* fourth = new ListNode(-4);

    // Linking nodes
    head->next = second;
    second->next = third;
    third->next = fourth;

    // Creating cycle (tail connects to second node)
    fourth->next = second;

    Solution obj;
    ListNode* result = obj.detectCycle(head);

    if(result != nullptr)
        cout << "Cycle detected at node with value: " << result->val << endl;
    else
        cout << "No cycle detected" << endl;

    return 0;
}