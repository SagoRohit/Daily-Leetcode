#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
        int minimumSum(int num) {
            vector<int> vc(4);
            while(num){
                vc.push_back(num%10);
                num/=10;
            }
            sort(vc.begin(),vc.end());
            int a=0, b=0;
            for(int i=0; i<vc.size(); i++){
                if(i%2==0)
                    a= a*10 + vc[i];
                else
                    b= b*10 + vc[i];
            }
            return a+b;
        }
    };
int main(){
    Solution sol;
    cout<<sol.minimumSum(4009)<<endl;
    return 0;
}