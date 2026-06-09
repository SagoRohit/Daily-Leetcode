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
    vector<TreeNode*> solve(int start, int end){
        // no element left
        if(start > end){
            return {NULL};
        }
        // only one element remains. so make it root and return
        else if(start == end){
            TreeNode* root = new TreeNode(start);
            return {root};
        }
        // so now, from start to end, we will make everyone root once and build bsts
        vector<TreeNode*> result; // result vector which may contain all the roots of solution
        for(int i = start; i <= end; i++){
            // recursively caluclate the left and right subtrees
            vector<TreeNode*> left_bsts  = solve(start, i-1);
            vector<TreeNode*> right_bsts = solve(i+1, end);

            // now travel each left and right subtrees and build the tree where 'i' is root
            for(TreeNode* leftroot: left_bsts){
                for(TreeNode* rightroot: right_bsts){
                    TreeNode* root = new TreeNode(i);
                    // now link the left and right child to the parent(root).
                    root->left = leftroot;
                    root->right = rightroot;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};