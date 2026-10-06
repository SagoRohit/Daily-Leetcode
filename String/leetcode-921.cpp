#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minAddToMakeValid(string s) {
        int lparen = 0;
        int balance = 0;
        for(char c : s) {
            if(c == '('){
                lparen ++;
            }else if(lparen > 0 ){
                lparen--;
            }else{
                balance++;
            }
        }
        return balance + lparen;
    }
};