#include<iostream>
#include<vector>
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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int& idx) {
        if(start > end)
            return NULL;
        int rootval = preorder[idx]; // preorder's idx val is the root val for that subtree
        int i = start;
        // findind root index in 'inorder'
        for(; i <= end; i++){
            if(inorder[i] == rootval)
                break;
        }
        idx++; // increament to find the next root for next recursive call
        TreeNode* root = new TreeNode(rootval); // creating the root node
        root->left = solve(preorder, inorder, start, i-1, idx); // explore left subtree
        root->right = solve(preorder, inorder, i+1, end, idx); // right subtree
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int idx = 0;
        return solve(preorder, inorder, 0, n-1, idx);
    }
};