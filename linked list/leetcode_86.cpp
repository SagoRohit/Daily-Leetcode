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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode(0);
        ListNode* others = new ListNode(0);

        ListNode* curr = head;
        ListNode* headless = less;
        ListNode* headothers = others;

        while(curr!=nullptr){
            ListNode* nextnode = curr->next;
            curr->next=nullptr;
            if(curr->val<x){
                less->next= curr;
                less = less->next;
            }else{
                others->next= curr;
                others= others->next;
            }
            curr = nextnode;
        }
        if(less!=nullptr && headothers->next!=nullptr)
            less->next=headothers->next;
        if(others!=nullptr)
            others->next=nullptr;
        if(headless!=nullptr && headless->next!=nullptr)
            return headless->next;
        return nullptr;
    }
};