#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void build(int i, int l, int r, vector<int> &baskets, vector<int> &segmentTree)
    {
        if (l == r) //leaf node
        {
            segmentTree[i] = baskets[l]; // assigning the value
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * i + 1, l, mid, baskets, segmentTree);  // building left child recursively
        build(2 * i + 2, mid + 1, r, baskets, segmentTree); // building right child recursively

        segmentTree[i] = max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);  // assigning the value
    }
    bool querysegmentTree(int i, int l, int r, vector<int> &segmentTree, int fruit)
    {
        if (segmentTree[i] < fruit) // max at the root
        {
            return false; // if it's less than the fruit, so it can't be placed any other basket
        }
        if (l == r) // reached leaf node
        {
            segmentTree[i] = -1;
            return true;
        }
        bool placed = false;
        int mid = l + (r - l) / 2;
        if (segmentTree[2 * i + 1] >= fruit) // now checking the left node if we can go
        {
            placed = querysegmentTree(2 * i + 1, l, mid, segmentTree, fruit);  // left query
        }
        else // so we can't go left, and so we are here to traverse in the right node
        {
            placed = querysegmentTree(2 * i + 2, mid + 1, r, segmentTree, fruit);  // right query
        }
        segmentTree[i] = max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);

        return placed;
    }
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
    {
        int n = baskets.size();
        vector<int> segmentTree(4 * n, -1);
        build(0, 0, n - 1, baskets, segmentTree); // build the tree

        int unplaced = 0;

        for (int &fruit : fruits)
        {
            if (querysegmentTree(0, 0, n - 1, segmentTree, fruit) == false) // checking if we can place the fruit or not
            {
                unplaced++;
            }
        }
        return unplaced;
    }
};