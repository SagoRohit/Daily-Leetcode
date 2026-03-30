#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int si=0;
        while(temp!=nullptr){
            temp= temp->next;
            si++;
        }
        // if it said to delete the head node, simply return the next node of head
        if(n==si){
            return head->next;
        }
        temp = head;
        // traverse to the (si-n-1)th node to delete the n-th node from the end
        // this ensures, we reach to the previous node of our concerned node.
        //here i represents the steps count;
        for(int i=0; i< si-n-1; i++){
            temp = temp->next;
        }
        // checking before deletion, it the temp is available or not.
        if (temp != nullptr && temp->next != nullptr) {
            temp->next = temp->next->next;
        }
        return head;
    }
};