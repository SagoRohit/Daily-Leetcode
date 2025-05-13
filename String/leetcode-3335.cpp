#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int mod = 1e9+7;
    int lengthAfterTransformations(string s, int t) {
        vector<int> mp(26,0);
        for(char ch: s){
            mp[ch-'a']++;
        }
        for(int count=1; count<=t; count++){
            vector<int> temp(26,0);
            for(int i=0; i<26; i++){
                char ch = i+ 'a';
                int freq = mp[i];
                
                if(ch!='z'){
                    temp[(ch+1)-'a'] = (temp[(ch+1)-'a']+freq)%mod;
                }else{
                    temp['a'-'a']= (temp['a'-'a']+freq)%mod;
                    temp['b'-'a']= (temp['b'-'a']+freq)%mod;
                }

            }
            mp= move(temp);
        }
        int result=0;
        for(int i=0; i<26;i++){
            result=(result+mp[i])%mod;
        }
        return result;
    }
};