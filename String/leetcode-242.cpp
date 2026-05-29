#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 100% beat
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return t==s;
    }
};

// another solution
// not that much good in terms of completion
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count(26,0);
        if(s.length()!=t.length())
            return false;
        for(int i=0; i<s.length(); i++){
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }
        for(int n: count){
            if(n!=0)
                return false;
        }
        return true;
    }
};