#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
       string dobl= s+s;
       string sub = dobl.substr(1, dobl.length()-2);
       return sub.find(s) != string::npos;
    }
};