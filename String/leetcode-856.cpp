#include<iostream>
#include<math.h>
using namespace std;
class Solution {
public:
// here we trace the depth of valid paren.
// when we find a () pair, then we calculate 2^depth, becuase we know (A) = 2*A
// and then accumulate with score.
    int scoreOfParentheses(string s) {
        int depth = 0;
        int score = 0;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '(')
                depth++;
            else
                depth--;
            if(s[i]==')' and s[i-1]=='(')
                score += pow(2,depth);
        }
        return score;
    }
};