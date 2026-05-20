#include<iostream>
#include<math.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        int original = x;
        if(x<0)
            return false;
        long long rev=0;
        while(x){
            rev = rev*10 + x%10;
            x/=10;
        }
        cout<<rev<<endl;
        return original==rev;
    }
};

int main(){ 
    Solution sol;
    cout<<sol.isPalindrome(121)<<endl;

    return 0;
}