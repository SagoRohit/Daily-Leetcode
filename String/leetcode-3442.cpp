#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
private:
    bool iseve(int n)
    {
        if(n%2==0)
            return true;
        return false;
    }
public:
    int maxDifference(string s) {
        vector<int> alpha(26,0);
        int len = s.length();
        int diff=0;
        for(int i=0; i<len; i++)
        {
            alpha[s[i]-'a']++;
        }
        sort(alpha.begin(), alpha.end());
        int i=25;
        while(i>=0 && (alpha[i]==0 || iseve(alpha[i]))){
            i--;
        }
        
        int a1= (i>=0)? alpha[i] : 0;
        i=0;
        while(i<26 && (alpha[i]==0 || !iseve(alpha[i])))
        {
            i++;
        }
       
        int a2 = (i<26)? alpha[i]:0;
        
        return a1-a2;
    }
};
int main(){
    Solution sol;
    string s = "aaaaabbc";
    cout<<sol.maxDifference(s)<<endl;
    return 0;
}