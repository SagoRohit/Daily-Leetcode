#include<iostream>
using namespace std;
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxalt = 0;
        int total = 0;
        for(int i=0; i<gain.size(); i++){
            total += gain[i];
            maxalt = max(maxalt, total);
        }
        return maxalt;
    }
};