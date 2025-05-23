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
            //checking if the left node is equal to val or not, if not then returns false and eventually return false
        if(!(inorder(root->left, val)))
            return false;
        if(root->val!=val)
            return false;
        // now traversing to right subtree
        return inorder(root->right, val);
    }
};