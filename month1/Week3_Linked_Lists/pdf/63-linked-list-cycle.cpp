// https://leetcode.com/problems/linked-list-cycle/

#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode * next;
    ListNode(){
        val = 0;
        next = nullptr;
    }
    ListNode(int x){
        val = x;
        next = nullptr;
    }
    ListNode(int x, ListNode * nextt){
        val = x;
        next = nextt;
    }
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode *,int> mp;
        ListNode* temp = head;
        while(temp){
            if(mp.find(temp)!= mp.end()){
                return true;
                break;
            }
            mp[temp] = 1;
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
