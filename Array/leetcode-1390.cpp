#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int divisorsum(int num)
    {
        int sum=0;
        int count=0;
        for(int i=2; i*i<=num; i++)
        {
            if(num%i==0){
                int j= num/i;
                if(i==j && count>0)
                    return 0;
                count++;
                sum += i+j;
            }   
        }
        if(count==0)
        return 0;

        return sum+1+num;

    }
    int sumFourDivisors(vector<int>& nums) {
        int sum=0;
        for(int num: nums)
        {
            sum+= divisorsum(num);
        }
        return sum;
    }
};
int main(){
    Solution sol;
    vector<int> arr= {21,21};
    cout<<sol.sumFourDivisors(arr)<<endl;
    return 0;
}