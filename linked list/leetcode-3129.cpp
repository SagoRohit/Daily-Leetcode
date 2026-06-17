#include<iostream>
#include<vector>
#include<stack>
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
class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;
        while(head!= nullptr){
            st.push(head->val);
            head = head->next;
        }
        int n = st.size();
        int result=0;
        int i = 0;
        while(i<n/2){
            result = max(result, temp->val+st.top());
            temp = temp->next;
            st.pop();
            i++;
        }
        return result;
    }
};