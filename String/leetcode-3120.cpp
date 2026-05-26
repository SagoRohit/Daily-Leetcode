#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lower(26,-1);
        vector<int> upper(26, -1);
        int count=0;
        for(char c: word){
            if(c>='a' and c<='z'){
                lower[c-'a']++;
            }else{
                upper[c-'A']++;
            }
        }
        for(int i=0; i<26; i++){
            if(lower[i]!=-1 and upper[i]!=-1)
                count++;
        }
        return count;
    }
};