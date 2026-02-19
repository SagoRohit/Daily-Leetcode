#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev=0, curr=1;
        int result=0;
        for(int i=1; i<s.length(); i++)
        {
            if(s[i-1]==s[i]){
                curr++;
            }else{
                result += min(prev, curr);
                prev= curr;
                curr=1;
            }
        }
        return result + min(prev,curr);
    }
};
int main(){
    string str = "00110011";
    Solution sol;
    cout<<sol.countBinarySubstrings(str)<<endl;
    return 0;
}