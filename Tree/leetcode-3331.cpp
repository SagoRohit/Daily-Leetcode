#include<iostream>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    bool solve(TreeNode* root){
        if(root->val==0)
            return false;
        if(root->val==1)
            return true;
        bool l  = solve(root->left);
        bool r = solve(root->right);
        if(root->val==2)
            return l|r;
        return l&r;
    }
    bool evaluateTree(TreeNode* root) {
        return solve(root);
    }
};