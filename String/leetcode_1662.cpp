#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
    public:
        bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
            string s2, s1;
            for(int i=0; i<word1.size(); i++)
                s1+= word1[i];
            for(int i=0; i<word2.size(); i++)
                s2+= word2[i];
            return s1==s2;   
        }
    };