#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n = 0;
        unordered_set<string> set(words.begin(), words.end());
        for(string word: words){
            reverse(word.begin(), word.end()); 
            if(set.count(word)>0)
                n++;
        }
        return n/2;
    }
};