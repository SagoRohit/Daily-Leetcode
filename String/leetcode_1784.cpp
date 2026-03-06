#include<iostream>
using namespace std;
class Solution {
public:
    bool checkOnesSegment(string s) {
        int i=0;
        while(i<s.length() && s[i]!='0')
            i++;
        if(i==s.length())
            return true;
        while(i<s.length() && s[i]!='1')
            i++;
        if(i==s.length())
            return true;
        else
            return false;
    }
};
int main(){
    Solution sol;
    string bin= "110011000000000111111111";
    cout<<sol.checkOnesSegment(bin);
    return 0;
}