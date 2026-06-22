#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> count(26,0);
        for(char c: text) {
            count[c-'a']++;
        }
        count['l'-'a'] /= 2;
        count['o'-'a'] /= 2;
        int result = INT_MAX;
        int b = 'b'-'a';
        int a = 'a'-'a';
        int l = 'l'-'a';
        int o = 'o'-'a';
        int n = 'n'-'a';
        result = min(count[b], result);
        result = min(count[a], result);
        result = min(count[l], result);
        result = min(count[o], result);
        result = min(count[n], result);
        return result;
    }
};