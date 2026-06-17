#include<iostream>
#include<vector>
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
    int pairSum(ListNode* head) {
        vector<int> value;
        while(head!=nullptr){
            value.push_back(head->val);
            head = head->next;
        }
        int result = 0;
        int n = value.size();
        for(int i=0; i<n; i++){
            result = max(result, value[i]+value[n-i-1]);
        }
        return result;
    }
};