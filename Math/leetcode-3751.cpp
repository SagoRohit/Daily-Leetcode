#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int waviness(int n){
        string num = to_string(n);
        int count = 0;
        for(int i=1; i<num.size()-1; i++){
            if(num[i]>num[i-1] and num[i]>num[i+1])
                count++;
            if(num[i]<num[i-1] and num[i]<num[i+1])
                count++;
        }
        return count;
    }
    int totalWaviness(int num1, int num2) {
        int count = 0;
        for(int i = num1; i<=num2; i++){
            if(i<100)
                continue;
            count += waviness(i);
        }
        return count;
    }
};
int main(){
    Solution sol;
    cout<<sol.totalWaviness(92, 161)<<endl;
    return 0;
}