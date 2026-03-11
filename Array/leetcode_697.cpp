#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int n: nums){
            map[n]++;
        }
        int maxfreq= INT_MIN;
        for(auto m:map){
            int freq = m.second;
            maxfreq = max(maxfreq, freq);
        }
        vector<vector<int>> maxvals;
        for(auto m: map){
            int val = m.first;
            int freq = m.second;
            if(freq == maxfreq){
                maxvals.push_back({val, freq});
            }
        }
        int inddiff=INT_MAX;
        for(auto info: maxvals){
            int start=0;
            int val = info[0];
            int freq = info[1];
            while(val!=nums[start])
                start++;
            int end = start;
            while(freq>0){
                if(nums[end]==val){
                    freq--;
                }
            }
            inddiff= min(inddiff, (end-start));
            
        }
        return inddiff+1;
    }
};
int main(){
    
    return 0;
}