/*559. Maximum Depth of N-ary Tree
Easy
Topics
Companies
Given a n-ary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

 

Example 1:



Input: root = [1,null,3,2,4,null,5,6]
Output: 3
Example 2:



Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: 5
 

Constraints:

The total number of nodes is in the range [0, 104].
The depth of the n-ary tree is less than or equal to 1000*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
class Solution {
public:
    int maxDepth(Node* root) {
        if(root == nullptr) return 0;
        int level=0;
        queue<Node*> pq;
        pq.push(root);
        while(!pq.empty()){
            level++;
            int depth = pq.size();
            for(int _ =0 ; _ <depth; ++_){
                auto node = pq.front();
                pq.pop();
                for(auto child: node->children){
                    if(child)
                        pq.push(child);
                }
            }
        }
        return level;
    }
};