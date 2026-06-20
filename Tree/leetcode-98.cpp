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
    bool isBST(TreeNode* root, TreeNode* min, TreeNode* max) {
        if(root == NULL)
            return true;
        if(min != NULL and root->val <= min->val)
            return false;
        if(max != NULL and root->val >= max->val)
            return false;
        return isBST(root->left, min, root) and isBST(root->right, root, max);
    }
    bool isValidBST(TreeNode* root) {
        return isBST(root, NULL, NULL);
    }
};