#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0)
            return false;
        while(n!=1){
            if(n%3!=0)
                return true;
            else
                n/=3;
        }
        return true;
    }
};

// here 1162261467 is the largest power-3th number of int which is 3^19. so if this is divisible by n, then obviously n is a power of 3.
// class Solution {
// public:
//     bool isPowerOfThree(int n) {
//         return n>0 && 1162261467%n==0;
//     }
// };