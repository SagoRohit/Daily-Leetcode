#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxDistance(string s, int k) {
        int x=0, y=0;
        vector<int> mandist;
        for(char c: s)
        {
            if(c=='E')
                x++;
            else if(c=='W')
                x--;
            else if(c=='N')
                y++;
            else
                y--;
            mandist.push_back(abs(x)+abs(y));
        }
        if(k==0)
        {
            return *max_element(begin(mandist), end(mandist));
        }
        int maxdis= mandist[1];
        int prev = mandist[0];
        int add =0;
        for(int i=1; i<mandist.size(); i++)
        {
            if(mandist[i]<prev && k>0)
            {
                add+=2;
                k--;
            }
            prev = mandist[i];
            mandist[i]+= add;
            maxdis= max(maxdis, mandist[i]);
        }
        return maxdis;
    }
};