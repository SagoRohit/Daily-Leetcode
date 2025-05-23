#include<iostream>
#include<vector>
#include<unordered_map>
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
    unordered_map<int, int> count;
    vector<int> findMode(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> result;
        inorder(root);
        int maxval =-1;
        for(auto it: count){
            if(maxval<it.second)
                maxval=it.second;
        }
        for(auto it: count){
            if(maxval==it.second)
                result.push_back(it.first);
        }
        return result;
        
    }
    void inorder(TreeNode* root){
        if(root==nullptr)
            return;
        inorder(root->left);
        count[root->val]++;
        inorder(root->right);
    }
};