#include<iostream>
#include<vector>
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
    ListNode* swapPairs(ListNode* head) {
       ListNode dummy(0);
        dummy.next=head;
        ListNode* prev = &dummy;
        while(prev->next!=nullptr && prev->next->next!=nullptr)
        {
            ListNode* first = prev->next;
            ListNode* second = first->next;

            //swap
            first->next= second->next;
            second->next=first;
            prev->next=second;

            prev=first;
        }
        return dummy.next;
    }
};