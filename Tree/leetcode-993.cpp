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
    TreeNode* xparent = nullptr;
    TreeNode* yparent = nullptr;
    int xdepth=-1;
    int ydepth=-1;
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, nullptr,0,x,y);
        return (xparent!=yparent) && (xdepth==ydepth);
    }
    void dfs(TreeNode* node, TreeNode* parent,int depth, int x, int y){
        if(!node)
            return;
        if(node->val==x){
            xdepth= depth;
            xparent= parent;
        }else if(node->val==y){
            ydepth= depth;
            yparent=parent;
        }
        if(xdepth!=-1 && ydepth!=-1)
            return;
        dfs(node->left,node,depth+1,x,y);
        dfs(node->right,node,depth+1,x,y);
    }
};