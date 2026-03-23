// https://leetcode.com/problems/copy-list-with-random-pointer/

#include<bits/stdc++.h>
using namespace std;


struct Node{
    int val;
    Node * next;
    Node * random;
    Node(){
        val = 0;
        next = nullptr;
        random = nullptr;
    }
    Node(int x){
        val = x;
        next = nullptr;
        random = nullptr;
    }
    Node(int x, Node * nextt){
        val = x;
        next = nextt;
        random = nullptr;
    }
    Node(int x, Node * nextt, Node * randomm){
        val = x;
        next = nextt;
        random = randomm;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node* temp = head;
        while(temp){
            Node* newNode = new Node(temp->val);
            mp[temp] = newNode;
            temp = temp->next;
        }
        temp = head;
        // Node* newList = Node(-1);
        while(temp){
            Node* copyNode = mp[temp];
            copyNode -> next = mp[temp->next];
            copyNode -> random = mp[temp->random];
            temp = temp->next;
        }
        return mp[head];
    }
};


// 🔹 Helper function to print list
void printList(Node* head) {
    while (head) {
        cout << "Val: " << head->val;

        if (head->random)
            cout << ", Random: " << head->random->val;
        else
            cout << ", Random: NULL";

        cout << endl;
        head = head->next;
    }
}

int main() {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    n1->random = n3;
    n2->random = n1;
    n3->random = n4;
    n4->random = n2;

    cout << "Original List:\n";
    printList(n1);

    Solution sol;
    Node* copiedHead = sol.copyRandomList(n1);

    cout << "\nCopied List:\n";
    printList(copiedHead);

    return 0;
}