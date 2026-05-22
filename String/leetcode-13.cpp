#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int len = s.length();
        vector<int> nums(len, 0);
        int sum = 0;
        for(int i=0; i<len; i++){
            switch (s[i])
            {
            case 'I':
                nums[i]=1;
                break;
            case 'V':
                nums[i]=5;
                break;
            case 'X':
                nums[i]=10;
                break;
            case 'L':
                nums[i]=50;
                break;
            case 'C':
                nums[i]=100;
                break;
            case 'D':
                nums[i]=500;
                break;
            default:
                nums[i]=1000;
                break;
            }
        }
        for(int i=0; i<len-1; i++){
            if(nums[i]<nums[i+1])
                sum-= nums[i];
            else 
                sum += nums[i];
        }
        sum += nums[len-1];
        return sum;
    }
};