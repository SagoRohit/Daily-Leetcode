#include<iostream>
#include<string>
#include<climits>
#include <cstdint>
#include<limits>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        long long  number=0;
        bool isneg=false;
        if(x<0)
            isneg=true;
        while(x){
            long long  rem = x%10;
            number= number*10.0 + rem;
            x/=10;
        }
        if(number > INT32_MAX || number < INT32_MIN) {
            return 0;
        }
        return number;
    }
};
int main(){
    Solution sol;
    cout<<sol.reverse(1534236469);
    return 0;
}