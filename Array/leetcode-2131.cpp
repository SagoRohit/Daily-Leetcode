#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        unordered_map<string, int> mp;
        int result=0;
        for(string &s: words){
            string revs = s;
            swap(revs[0],revs[1]);

            if(mp[revs]>0){
                result+=4;
                mp[revs]--;
            }else{
                mp[s]++;
            }
        }
        for(auto &it: mp){
            string word= it.first;
            int count= it.second;
            if(word[0]==word[1] && count>0){
                result+=2;
                break;
            }
        }
        return result;
    }
};