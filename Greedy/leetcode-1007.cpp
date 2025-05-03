#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int find(vector<int>& top, vector<int> &bot, int val){
        int swaptop=0, swapbottom=0;
        int n = top.size();
        for(int i=0; i<n; i++){
            if(top[i]!=val && bot[i]!=val)
                return -1;
            else if(top[i]!=val)
                swaptop++;
            else if(bot[i]!=val)
                swapbottom++;
        }
        return min(swaptop, swapbottom);
    }
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        int result=INT_MAX;
        for(int val=1; val<=6; val++){
            int steps= find(tops, bottoms,val);
            if(steps!=-1)
                result = min(result, steps);
        }
        return result==INT_MAX? -1: result;
    }
};