#include<iostream>
using namespace std;
class Solution {
    public:
        int countDigits(int num) {
            int count=0;
        int rela = num;
            while(num){
                int rem = num%10;
                if(rela%rem==0)
                    count++;
                num/=10;
            }
            return count;
        }
    };