#include<iostream>
using namespace std;
class Solution {
public:
    int reverseBits(int n) {
        if(n==0)
            return 0;
        int result = 0;
        for(int i=0; i<32; i++) {
            result <<= 1; // left shift result by 1
            result |= (n&1); // add the last bit of n with result
            n >>= 1; // right shift n by 1
        }
        return result;
    }
};