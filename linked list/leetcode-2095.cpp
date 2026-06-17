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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr or head->next == nullptr)
            return NULL;
        ListNode* prev;
        ListNode* slow = head;
        ListNode* fast = head;
        // finding mid
        while(fast!=NULL and fast->next!=NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        // deletion
        prev->next = slow->next->next;
        return head;
    }
};