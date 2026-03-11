#include<iostream>
#include<cstring>
using namespace std;
class Solution {
public:
    int M = 1e9+7;
    int t[201][201][2];
    // int solve(int oneleft, int zeroleft, bool prevwasone, int limit){
    //     if(oneleft==0 and zeroleft==0)
    //         return 1;
    //     if(t[oneleft][zeroleft][prevwasone]!=-1)
    //         return t[oneleft][zeroleft][prevwasone];
    //     int result=0;
    //     if(prevwasone){
    //         // now we will explore 0s
    //         for(int len=1; len<= min(zeroleft, limit); len++){
    //             result = (result + solve(oneleft, zeroleft-len, false, limit)) % M;
    //         }
    //     }else{
    //         // now we will explore 1s
    //         for(int len=1; len<= min(oneleft, limit); len++){
    //             result = (result + solve(oneleft-len, zeroleft, true, limit)) % M;
    //         }
    //     }
    //     return t[oneleft][zeroleft][prevwasone]=result;
    // }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(t, -1, sizeof(t));
        t[0][0][0]=1;
        t[0][0][1]=1;

        for(int zeroleft=0; zeroleft<=zero; zeroleft++){
            for(int oneleft=0; oneleft<=one; oneleft++){
                if(zeroleft==0 and oneleft==0)
                    continue;
                int result=0;
                // exploring 0s
                for(int len =1 ; len<= min(zeroleft, limit); len++){
                    result = (result + t[oneleft][zeroleft-len][0])%M;
                }
                t[oneleft][zeroleft][1]=result;
                result=0;
                // exploring 1s
                for(int len =1; len<= min(oneleft, limit); len++){
                    result = (result + t[oneleft-len][zeroleft][1]) % M;
                }
                t[oneleft][zeroleft][0]=result;
            }
        }
        int startwithone = t[one][zero][0]; //solve(one, zero, false, limit) % M;
        int startwithzero = t[one][zero][1]; //solve(one, zero, true, limit) % M;

        return (startwithone+startwithzero) % M;
    }
};
int main(){
    Solution sol;
    cout<<sol.numberOfStableArrays(2,1,1);
    return 0;
}   