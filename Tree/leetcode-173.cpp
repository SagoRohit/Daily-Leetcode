#include<iostream>
#include<stack>
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
class BSTIterator {
public:
    stack<TreeNode*> st;
    void storeLeftNodes(TreeNode* root){
        while(root != NULL){
            st.push(root);
            root = root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        storeLeftNodes(root);
    }
    
    int next() {
        TreeNode* ans = st.top();
        st.pop();
        storeLeftNodes(ans->right);
        return ans->val;
    }
    
    bool hasNext() {
        return st.size()>0;
    }
};
// here we are storing all the left child of root. and while calling the next() func, 
// we do check if there is any right child, if it does have then we store all the left childs of 
// that ans->right node. 
// this ensures, we do not call inorder everytime. and stack does not cross max height of bst.