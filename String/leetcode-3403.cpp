#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    string answerString(string word, int num)
    {
        int n = word.length();
        if(num==1)
            return word;
        string result ;
        int possible = n- (num-1);
        for (int i = 0; i < n; i++)
        {
            int takelen= min(possible, n-i);
            result = max(result,word.substr(i,takelen));
        }
        return result;
    }
};