#include <iostream>
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
class Solution
{
public:
    bool isUnivalTree(TreeNode *root)
    {
        return inorder(root, root->val);
    }
    bool inorder(TreeNode* root, int val){
        if(!root)
            return true;
        if(!(inorder(root->left, val)))
            return false;
        if(root->val!=val)
            return false;
        return inorder(root->right, val);
    }
};