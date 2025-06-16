#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
class Solution {
public:
    int maxDiff(int num) {
        string digit=to_string(num);
        int mini;
        if(digit[0]=='1'){
            int i=1;
            while(digit[i]=='0')
                i++;
            char grp = digit[i];
            for(;i<digit.length(); i++){
                if(digit[i]==grp)
                {
                    digit[i]='0';
                }
            }
        }else{
            char grp = digit[0];
            for(int i=0; i<digit.length();i++)
            {
                if(digit[i]==grp)
                {
                    digit[i]='1';
                }
            }
        }
        mini=stoi(digit);
        digit=to_string(num);
        int i=0;
        while(digit[i]=='9')
            i++;
        char grp = digit[i];
        for(; i<digit.length();i++)
        {
            if(digit[i]==grp){
                digit[i]='9';
            }
        }
        int maxi=stoi(digit);
        cout<<maxi<<" "<<mini<<endl;
        return maxi-mini;
    }
};
int main(){
    Solution sol;
    cout<<sol.maxDiff(9288);
    return 0;
}