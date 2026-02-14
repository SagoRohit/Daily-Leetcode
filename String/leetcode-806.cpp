#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines=1;
        int countwidth=0;
        for(char c: s){
            int w= widths[c-'a'];
            if(countwidth+w>100){
                lines++;
                countwidth=w;
            }else{
                countwidth+=w;
            }
        }
        return {lines, countwidth};
    }
};