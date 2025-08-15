#include<iostream>
using namespace std;
class Solution {
public:
    bool isPowerOfFour(int n) {
        int mask = 0b01010101010101010101010101010101;
        if(n<=0)
            return false;
         return ((mask | n) == mask) && ((n & (n-1)) == 0);
    }
};
int main(){
    Solution sol;
    cout<<sol.isPowerOfFour(2);
    return 0;
}