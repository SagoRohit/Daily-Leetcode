
#include <iostream>
#include <queue>
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
    int summa(TreeNode *node)
    {
        if (node == nullptr)
            return 0;

        return (node->val + summa(node->left) + summa(node->right));
    }
    int nodecnt(TreeNode *node)
    {
        int count = 0;
        queue<TreeNode *> q;
        q.push(node);
        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();
            count++;
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
        return count;
    }
    int averageOfSubtree(TreeNode *root)
    {
        int count = 0;
        vector<int> totals;
        vector<int> nodecount;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();
            int sum = summa(front);
            int nodecount = nodecnt(front);
            if (front->val == (sum / nodecount))
                count++;
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
        return count;
    }
};