#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<string> result;
        int prev = -1, i=0;
        for(int &b: groups){
            if(b!=prev){
                result.push_back(words[i]);
                prev = b;
            }  
            i++;
        }
        return result;
    }
};