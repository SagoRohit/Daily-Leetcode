#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
class Solution {
public:
    int t[1001][1001];
    bool solve(int i, int j, string& s){
        if(i>=j)
            return 1;
        if(t[i][j]!=-1)
            return t[i][j];
        if(s[i]==s[j])
            return t[i][j]=solve(i+1, j-1, s);
        else 
            return t[i][j]=0;
    }
    string longestPalindrome(string s) {
        int n= s.length();
        memset(t, -1, sizeof(t));
        int sp=0;
        int maxlen= INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(solve(i,j, s)){
                    if(j-i+1>maxlen){
                        maxlen = j-i+1;
                        sp = i;
                    }
                }
            }
        }
        return s.substr(sp, maxlen);
    }
};