#include<iostream>
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr)
            return head;  // if there is nothing, return nothing
        if(k==0)
            return head; // if no rotation needed, then return head
        
        int n=0;
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        ListNode* temp = dummy->next; 

        // finding the size of the given list
        while(temp!= nullptr){
            n++;
            temp = temp->next;
        }
        if(n!=0)
            k= k%n;
        if(k==0)
            return head; // again, if no rotaion needed, then return head
        for(int i=0; i<k; i++){
            fast= fast->next;
        }
        // here we are using the concep of leetcode-19 one pass approach, 
        // where we delete the n-th node from the end. and before that, we find the 
        // n-th node using an one pass approach. and here we do the same.
        while(fast->next!=nullptr){
            fast= fast->next;
            slow= slow->next;
        }
        // we breaking the link, join it to the dummy.next
        temp = dummy->next;
        dummy->next= slow->next;
        slow->next=nullptr;
        fast->next=temp;
        return dummy->next;
    }
};