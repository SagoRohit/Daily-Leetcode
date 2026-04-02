#include<iostream>
#include<unordered_map>
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
        if(head==nullptr)
            return nullptr;
        Node* curr = head;
        Node* newHead= nullptr;
        Node* prev = nullptr;
        unordered_map<Node*, Node*> mp;

        // creating the deep copy linked list (without random pointer)
        while(curr){
            Node* temp = new Node(curr->val);
            mp[curr] = temp;
            if(newHead==nullptr){
                newHead = temp; // staring of the new list
            }else{
                prev->next = temp; // crating connection
            }
            prev = temp; 
            curr = curr->next;
        }

        // now assigning random pointer
        curr = head;
        Node* newCurr = newHead;
        while(curr){
            if(curr->random==NULL){
                newCurr->random = NULL;
            }else{
                newCurr->random = mp[curr->random]; // equivalent node of curr.random will be the random pointer of newly crated node's random pointer
            }
            curr = curr->next; // moving forward
            newCurr = newCurr->next;
        }
        return newHead;
    }
};