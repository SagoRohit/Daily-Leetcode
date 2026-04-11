#include <iostream>
#include <queue>
#include <vector>
#include<algorithm>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (root == nullptr)
            return result;
        queue<TreeNode *> qu;
        qu.push(root);
        int lvl = 0;
        while (!qu.empty())
        {
            int size = qu.size();
            vector<int> level;
            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = qu.front();
                qu.pop();
                level.push_back(curr->val);
                if (curr->left)
                    qu.push(curr->left);
                if (curr->right)
                    qu.push(curr->right);
            }
            if (lvl % 2 != 0)
                reverse(level.begin(), level.end());
            result.push_back(level);
            lvl++;
        }
        return result;
    }
};