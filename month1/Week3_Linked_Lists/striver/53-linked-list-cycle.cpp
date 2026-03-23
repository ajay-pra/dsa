// https://leetcode.com/problems/linked-list-cycle/submissions/1950300325/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* temp = head;
        unordered_map<ListNode *, int> mp;
        int count = 1;

        while(temp){
            if(mp.find(temp) != mp.end()){
                return true;
            }
            mp[temp] = count;
            count++;
            temp = temp->next;
        }
        return false;
    }
};


// Another way is by using turtois and hair algorithm
class Solution2 {
public:
    bool hasCycle2(ListNode *head) {
        ListNode* fp = head;
        ListNode* sp = head;
        while(fp && fp->next){
            sp = sp-> next;
            fp = fp->next->next;
            if(sp == fp) return true;
        }
        return false;
    }
};


int main() {

    // Creating nodes
    ListNode* head = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);

    // Linking nodes
    head->next = node2;
    node2->next = node3;
    node3->next = node4;

    // Creating a cycle
    node4->next = node2;   // cycle here

    Solution obj;

    if(obj.hasCycle(head))
        cout << "Cycle Detected" << endl;
    else
        cout << "No Cycle" << endl;

    return 0;
}