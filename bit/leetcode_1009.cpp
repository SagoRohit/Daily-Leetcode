#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
class Solution {
public:
    string binaryComplement(int n)
    {
        string binary="";
        if(n==0)    
            return "1";
        while(n>0){
            binary+= (n&1)? '0':'1';
            n>>=1;
        }
        reverse(binary.begin(), binary.end());
        return binary;
    }
    int intoInteger(string bin){
        int n = bin.length();
        int power=0;
        int integer=0;
        for(int i = n-1; i>=0; i--){
            if(bin[i]=='1'){
                integer+= pow(2, power);
            }
            power++;
        }
        return integer;
    }
    int bitwiseComplement(int n) {
        string combin = binaryComplement(n);
        cout<<combin<<endl;
        return intoInteger(combin);
    }
};
int main(){
    Solution sol;
    cout<<sol.bitwiseComplement(0)<<endl;
    return 0;
}