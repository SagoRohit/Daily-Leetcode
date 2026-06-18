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
    void flatten(TreeNode* root) {
        if(!root)
            return;
        root = solve(root);
    }
    TreeNode* solve(TreeNode* root){ // defined to do root->left->right;
        if(!root)
            return NULL;
        TreeNode* lefthead = solve(root->left); // left traversal
        TreeNode* righthead = solve(root->right); //right traversal
        root->left = NULL; // left of each node will be NULL
        if(lefthead){ // if there was a left subtree
            root->right = lefthead;
            TreeNode* temp = lefthead;
            while(temp->right)
                temp = temp->right;
            temp->right = righthead; // root->left->right ;
        }else{
            root->right = righthead; //root -> right, because no left subtree is available;
        }
        return root;
    }
};