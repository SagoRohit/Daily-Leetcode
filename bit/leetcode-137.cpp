/*
Two important points:
    1. How to find if i-th bit is 1 or 0?
    ans: if(num & (1<<i) != 0)
            then i-th bit is 1
        else 
            i-th bit is 0
    2. How to set the i-th bit
    ans: num = num | (1<<i);
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(int i=0; i<32; i++) { // here we will try to find if i bit is set for all numbers in the array.
            int setcount = 0;
            for(int num: nums) {
                if((num & (1<<i))!=0) // to check if the i-th bit is set or not
                    setcount++;
            }
            if(setcount%3!=0) // if the i-th bit set count is not divisible by 3, it means this bit is set in the result 
                result = result | (1<<i); // set that i-th bit in the result
        }
        return result;
    }
};