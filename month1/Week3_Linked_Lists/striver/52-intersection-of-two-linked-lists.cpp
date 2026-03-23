
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while(tempA != tempB){

            if(tempA == nullptr)
                tempA = headB;
            else
                tempA = tempA->next;

            if(tempB == nullptr)
                tempB = headA;
            else
                tempB = tempB->next;
        }

        return tempA;
    }
};

int main() {

    // Common intersection part
    ListNode* intersect = new ListNode(8);
    intersect->next = new ListNode(9);

    // List A: 1 -> 2 -> 3 -> 8 -> 9
    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = intersect;

    // List B: 4 -> 5 -> 8 -> 9
    ListNode* headB = new ListNode(4);
    headB->next = new ListNode(5);
    headB->next->next = intersect;

    Solution obj;
    ListNode* ans = obj.getIntersectionNode(headA, headB);

    if(ans)
        cout << "Intersection Node Value: " << ans->val << endl;
    else
        cout << "No Intersection" << endl;

    return 0;
}