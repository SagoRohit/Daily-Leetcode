#include<iostream>
#include<vector>
#include<queue>
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
    int maxLevelSum(TreeNode* root) {
        if(root==NULL)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int maxlvl=1;
        int lvl=1;
        int maxval= INT_MIN;
        while(!q.empty()){
            int lvlsum=0;
            int size= q.size();
            for(int i=0; i<size; i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                lvlsum+= curr->val;
            }
            if(lvlsum>maxval){
                maxlvl=lvl;
                maxval=lvlsum;
            }
            lvl++;
        }
        return maxlvl;
    }
};