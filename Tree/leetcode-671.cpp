#include<iostream>
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
    int findSecondMinimumValue(TreeNode* root) {
        if(!root)
            return -1;
        int rootval= root->val;
        int secmin = dfs(root, rootval);
        return secmin==INT_MAX? -1: secmin;
    }
    int dfs(TreeNode* root, int rootval){
        if(!root){
            return -1;
        }
        if(root->val>rootval)
            return root->val;
        int left = dfs(root->left, rootval);
        int right = dfs(root->right, rootval);
        if(left==-1)
            return right;
        if(right==-1)
            return left;
        return min(left, right);
    }
};