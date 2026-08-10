#include<iostream>
using namespace std;
class Solution {
public:
    int productofdigits(int n) {
        long long product=1;
        while(n) {
            product *= n%10;
            n/=10;
        }
        return product;
    }
    int smallestNumber(int n, int t) {
        while(true){
            if(productofdigits(n)%t==0)
                return n;
            n++;
        }
        return 0;
    }
};
int main(){
    Solution sol;
    cout<<sol.smallestNumber(10,2);
    return 0;
}