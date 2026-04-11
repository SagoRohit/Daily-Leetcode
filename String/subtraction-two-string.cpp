#include<iostream>
#include<algorithm>
using namespace std;
string subtraction(string s1, string s2){
    int i = s1.length()-1;
    int j = s2.length()-1;
    int borrow = 0;
    string result="";
    while(i>=0 and j>=0){
        int a = s1[i]-'0';
        int b = s2[j]-'0';
        int sub = a-b-borrow;
        if(sub<0){
            sub+= 10;
            borrow = 1;
        }else{
            borrow = 0;
        }
        result += sub+'0';
        i--;
        j--;
    }
    while(i >= 0){
        int a = s1[i] - '0';
        int sub = a - borrow;

        if(sub < 0){
            sub += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result += (sub + '0');
        i--;
    }
    reverse(result.begin(), result.end());
    int k =0;
    while(k<result.length()-1 and result[k]=='0')
        k++;
    return result.substr(k);
}