#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        // now swap require
        if(s1==s2)
            return true;
        // 0 1 swap require
        swap(s1[1],s1[3]);
        if(s1==s2)
            return true;
        // 1 1 swap require
        swap(s1[0], s1[2]);
        if(s1==s2)
            return true;
        // 1 0 swap require, re-swap 1, 3 index (basically undo the prev swap)
        swap(s1[1],s1[3]);
        if(s1==s2)
            return true;
        return false;
    }
};
int main(){
    Solution sol;
    string s1 = "abcd";
    string s2 = "cdab";
    cout<<sol.canBeEqual(s1,s2);
    return 0;
}