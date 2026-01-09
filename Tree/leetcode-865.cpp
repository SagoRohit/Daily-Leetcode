#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root==NULL)
            return nullptr;
        queue<TreeNode*> pq;
        pq.push(root);
        vector<TreeNode*> latest;
        unordered_map<TreeNode*, TreeNode*> parent;
        parent[root]= nullptr;
        while(!pq.empty())
        {
            int size= pq.size();
            latest.clear();
            for(int i=0; i<size; i++)
            {
                TreeNode* curr = pq.front();
                pq.pop();
                latest.push_back(curr);
                if(curr->left)
                {
                    parent[curr->left]= curr;
                    pq.push(curr->left);
                }
                if(curr->right)
                {
                    parent[curr->right]= curr;
                    pq.push(curr->right);
                }
            }
        }
        unordered_set<TreeNode*> deepest(latest.begin(), latest.end());
        while(deepest.size()>1)
        {
            unordered_set<TreeNode*> next;
            for(auto node: deepest)
            {
                next.insert(parent[node]);
            }
            deepest=next;
        }
        return *deepest.begin();
    }
};