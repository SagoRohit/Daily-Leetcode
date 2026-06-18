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
        // if root is null or it does not have any child, then return root;
        if(root == NULL or root->left==NULL) // as it is a complete bt, only need to check left child
        // if left child is not available, then right won't be available;
            return root;
        queue<Node*> q;
        q.push(root);
        q.push(NULL); // mark the end of level;
        // level order traversal;
        Node* prev = NULL;
        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();
            if(curr == NULL) {
                if(q.size()==0) // so the queue is empty, so break the loop;
                    break;
                q.push(NULL); // mark the end of level;
            }else {
                if(curr->left != NULL) // left child not empty;
                    q.push(curr->left);
                if(curr->right != NULL) // right child not empty;
                    q.push(curr->right);
                if(prev!=NULL)
                    prev->next = curr; // connect the pointer;
            }
            prev = curr; // update the prev;
        }
        return root;
    }
};