#include<iostream>
using namespace std;
// here the core idea is to find the prefix of left and right. and then pad i amount of 0 at the end of common prefix.
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int i=0;
        while(left != right) {
            left >>= 1; // right shifting to find the common prefix
            right >>= 1;
            i++; // shift count
        }
        left <<= i; // now pad zero.
        // so this is how did this :3
        return left; 
    }
};