#include<iostream>
using namespace std;
class Solution {
public:
    int sumofdigit(int n){
        int sum =0;
        while(n){
            sum += n%10;
            n/=10;
        }
        return sum;
    }
    int reverseint(int n){
        int reverseinit = 0;
        while(n){
            int digit = n % 10;
            reverseinit =  reverseinit * 10 + digit;
            n/=10;
        }
        return reverseinit;
    }
    long long formint(int n){
        long long result=0;
        while(n){
            if(n%10!=0){
                result = result * 10 + n%10;
            }
            n/=10;
        }
        return reverseint(result);
    }
    long long sumAndMultiply(int n) {
        int x = sumofdigit(n);
        long long result = x * formint(n);
        return result;
    }
};