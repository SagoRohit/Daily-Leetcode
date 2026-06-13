#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result="";
        for(string s: words){
            int sum = 0;
            for(char c: s){
                sum += weights[c-'a'];
            }
            sum %= 26;
            result += ('a'+ abs(sum-25));
        }
        return result;
    }
};