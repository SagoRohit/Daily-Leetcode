#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<math.h>
#include<bitset>
using namespace std;
class Solution {
public:
    string intobinary(int num, int n){
        string binary="";
        for(int i=n-1; i>=0; i--)
        {
            binary+= ((num >> i) & 1)? '1':'0';
        }
        return binary;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        const int n = nums.size();
        int upper= pow(2,n)-1;
        int result;
        set<int> possiblecandidate;
        for(string bin: nums)
        {
            possiblecandidate.insert(stoi(bin, nullptr, 2));
        }
        for(int i=0; i<= upper; i++){
            if(possiblecandidate.count(i)==0)
            {
                result= i;
                break;
            }
        }
        string binary = intobinary(result,n);
        return binary;
    }   
};
int main(){
    Solution sol;
    vector<string> nums={"00","10"};
    cout<<sol.findDifferentBinaryString(nums);
    return 0;
}