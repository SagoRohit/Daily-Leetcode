/*530. Minimum Absolute Difference in BST
Easy
Topics
Companies
Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.



Example 1:


Input: root = [4,2,6,1,3]
Output: 1
Example 2:


Input: root = [1,0,48,null,null,12,49]
Output: 1


Constraints:

The number of nodes in the tree is in the range [2, 104].
0 <= Node.val <= 105
 */
#include <iostream>
#include <vector>
#include<climits>
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
    int mindiff=INT_MAX;
    int preval =-1;
    void travarse(TreeNode* root){
        if(!root) return;
        travarse(root->left);
        if(preval!=-1){
            mindiff= min(mindiff, root->val-preval);
        }
        preval = root->val;
        travarse(root->right);
    }
    int getMinimumDifference(TreeNode *root){
        travarse(root);
        return mindiff;
    }
    
};