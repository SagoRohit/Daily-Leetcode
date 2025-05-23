#include<iostream>
#include<string>
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
    string dfs(TreeNode* root){
        if(!root)
            return "#";
        return "^" + to_string(root->val) + "," + dfs(root->left) + "," + dfs(root->right);
        
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string maintree = dfs(root);
        string subtree = dfs(subRoot);
        return maintree.find(subtree) != string::npos;
    }
};
