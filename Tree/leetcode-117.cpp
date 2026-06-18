#include<iostream>
#include<queue>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL or root->left==NULL or root->right==NULL)
            return root;
        queue<Node*> q;
        q.push(root);
        q.push(NULL); // mark the end of level;
        Node* prev = NULL;
        while(!q.empty()) {
            Node* curr = q.front(); // find the current element;
            q.pop();
            if(curr == NULL){
                if(q.size()==0)
                {
                    break;
                }
                q.push(NULL); // mark the end of the level;
            }else{
                if(curr->left!=NULL){
                    q.push(curr->left); // push the left child;
                }
                if(curr->right!=NULL){ 
                    q.push(curr->right); // push the right child;
                }
                if(prev!=NULL)
                    prev->next = curr; // if prev is not null, then connect;
            }
            prev = curr; // update the prev;
        }
        return root;
    }
};