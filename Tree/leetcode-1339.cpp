#include<iostream>
#include<vector>
#include<queue>
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
    long long ans=0;
    long long mod = 1e9+7;
    long long dfs(TreeNode* node){
        if(!node)
            return 0;
        node->val += dfs(node->left) + dfs(node->right);
        return node->val;
    }
    int maxProduct(TreeNode* root) {
        long long sum= dfs(root);
        queue<TreeNode*> pq;
        pq.push(root);
        while(!pq.empty()){
            TreeNode* curr = pq.front();
            pq.pop();
            if(!curr)
                continue;
            long long result= (sum-curr->val)*curr->val;
            ans = max(ans, result);
            if(curr->left)
                pq.push(curr->left);
            if(curr->right)
                pq.push(curr->right);
        }
        return ans;
    }
};