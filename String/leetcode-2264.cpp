#include<iostream>
using namespace std;
class Solution {
public:
    string largestGoodInteger(string& num) {
        int count =0;
        char prev = 'a', maxgood= ' ';
        for(char ch: num)
        {
            if(ch==prev)
                count++;
            else 
                count=1;
            if(count==3)
                maxgood= max(ch,maxgood);
            prev =ch;
        }
        return (maxgood==' ')?"":string(3,maxgood);
    }
};