#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l=0, r=0, neu=0;
        for(char c: moves){
            if(c=='L')
                l++;
            else if(c=='R')
                r++;
            else
                neu++;
        }
        return neu + abs(r-l); 
    }
};