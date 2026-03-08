#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool checkRecord(string s) {
        int a=0;
        int l=0;
        for(char c: s)
        {
            if(c=='A'){
                a++;
                l=0;
            }   
            if(a==2)
                return false;
            if(c=='L'){
                l++;
            }
            if(l==3)
                return false;
            if(c=='P'){
                l=0;
            }
        }
        return true;
    }
};