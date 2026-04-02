#include<iostream>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head ==NULL)
            return NULL;
        // 1) first step to create new duplicate nodes in between the original nodes
        Node* curr = head;
        while(curr){ // A -> B
            Node* currNext = curr->next; // storign B
            curr->next = new Node(curr->val); // creating new node, and assiging it to A -> x
            curr->next->next = currNext; // connect x->B
            curr = currNext; // shift curr pointer to B
        }

        // 2) second step, now we assing the random pointers to the duplicate nodes
        curr = head;
        while(curr!= NULL && curr->next!=NULL){
            if(curr->random==NULL){
                curr->next->random = NULL;  // A -> x -> B. curr is always in the original nodes
            }else{
                curr->next->random = curr->random->next; // curr er random ee giye, tar next tai hocche setar duplicate
            }
            curr = curr->next->next;
        }

        // 3) third step, now we seperate the original and duplicate nodes
        curr = head;
        Node* newHead = head->next;
        Node* newCurr = newHead;
        while(curr != NULL && newCurr != NULL){
            curr->next = (curr->next==NULL)? NULL : curr->next->next;
            newCurr->next = (newCurr->next==NULL)? NULL : newCurr->next->next;
            curr = curr->next;
            newCurr = newCurr->next;
        }
        return newHead;
    }
};