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
    int solve(TreeNode* root, int curr){
        if(!root)
            return 0;
        curr = curr * 10 + root->val;
        // we found a root to leaf path
        if(root->left==NULL and root->right==NULL)
            return curr;
        int leftsum = solve(root->left, curr);
        int rightsum = solve(root->right, curr);
        // sum of left and right path number;
        return leftsum + rightsum;
    }
    int sumNumbers(TreeNode* root) {
        return solve(root, 0);
    }
};