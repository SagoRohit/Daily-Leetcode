#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minFlips(string s) {
        int n= s.length();
        int flip1=0;
        int flip2=0;
        int result = INT_MAX;


        //now sliding window
        int i=0, j=0;
        while(j<2*n)
        {
            char ex1= (j%2)? '1':'0';
            char ex2= (j%2)? '0':'1';
            if(s[j%n]!=ex1)
            {
                flip1++;
            }
            if(s[j%n]!=ex2)
            {
                flip2++;
            }
            if(j-i+1>n) // time to shrink
            {
                char ex1= (i%2)? '1':'0';
                char ex2= (i%2)? '0':'1';
                if(s[i%n]!=ex1){
                    flip1--;
                }
                if(s[i%n]!=ex2){
                    flip2--;
                }
                i++;
            }
            if(j-i+1==n){
                result = min({result, flip1, flip2});
            }
            j++;
        }
        return result;
    }
};
int main(){
    Solution sol;
    string bin = "01001001101";
    cout<<sol.minFlips(bin)<<endl;
    return 0;
}