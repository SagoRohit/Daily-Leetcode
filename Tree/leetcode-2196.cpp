#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
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
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> childset;
        for(vector<int> vec: descriptions)
        {
            // extracting information here
            int parent = vec[0]; 
            int child  = vec[1];
            int ischild = vec[2];
            if(mp.find(parent)==mp.end()){ // to check if the parent node is created or not
                mp[parent] = new TreeNode(parent); // not present in mp, so create one
            }
            if(mp.find(child)==mp.end()){ // to check if the child node is created or not
                mp[child] = new TreeNode(child); // not present in mp, so create one
            }
            if(ischild==1){ // left child
                mp[parent]->left = mp[child];
            }else{ // right child
                mp[parent]->right = mp[child];
            }
            childset.insert(child); // inserting all the childs
        }
        for(vector<int> vec: descriptions) // find the root node. which is not present in the child set.
        {
            int parent = vec[0];
            if(childset.find(parent)==childset.end()){
                return mp[parent];
            }
        }
        return NULL; // never reach here
    }
};