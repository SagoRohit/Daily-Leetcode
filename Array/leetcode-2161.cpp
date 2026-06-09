#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        vector<int> lessval;
        vector<int> pivotval;
        vector<int> greaterval;
        //vector<int> result;
        for (int n : nums)
        {
            if (n < pivot)
                lessval.push_back(n);
            else if (n == pivot)
                pivotval.push_back(n);
            else
                greaterval.push_back(n);
        }
        // for(int i=0; i<lessval.size(); i++){
        //     result.push_back(lessval[i]);
        // }
        for(int i=0; i<pivotval.size(); i++){
            lessval.push_back(pivotval[i]);
        }
        for(int i=0; i<greaterval.size(); i++){
            lessval.push_back(greaterval[i]);
        }
        return lessval;
    }
};