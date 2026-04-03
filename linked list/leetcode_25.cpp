#include<iostream>
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt =0;

        // to check if there exits k node
        while(cnt < k){
            if(temp==NULL)
                return head;
            temp = temp->next;
            cnt++;
        }
        // recursive call to solve the rest of the nodes of the list
        ListNode* prevNode = reverseKGroup(temp, k); // it will return the head

        temp = head, cnt = 0;
        // here we reversing the group 
        while(cnt < k){
            ListNode* next = temp->next; // store the temp.next
            temp->next = prevNode; // temp.next er sathe connection done
            prevNode = temp; // prevnode update
            temp = next; // temp update
            cnt++;
        }
        return prevNode;
    }
};