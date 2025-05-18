#include<iostream>
using namespace std;
class Solution {
public:
    bool isThree(int n) {
        if(n==1 || n==2 || n==3)
            return false;
        int count=1;
        for(int i=2; i<=n; i++){
            if(n%i==0)
                count++;
        }
        return (count==3)? true: false;
    }
};