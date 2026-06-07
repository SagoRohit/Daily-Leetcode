#include<iostream>
#include<vector>
using namespace std;

// brute force solution
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int finaltime = INT_MAX;

        // if we start with land ride.
        for(int i=0; i<landStartTime.size(); i++){
            for(int j=0; j<waterStartTime.size(); j++){
                int tempfinishtime = 0;
                int landfinish = landStartTime[i]+landDuration[i];
                if(landfinish<waterStartTime[j]){ // if landride finishes before waterride
                    tempfinishtime = waterStartTime[j] + waterDuration[j];
                }else{
                    tempfinishtime = landfinish + waterDuration[j];
                }
                finaltime = min(finaltime, tempfinishtime);
            }
        }
        // what if we start with water ride?
        for(int i=0; i<waterStartTime.size(); i++){
            for(int j=0; j<landStartTime.size(); j++){
                int tempfinishtime = 0;
                int waterfinishtime = waterStartTime[i] + waterDuration[i];
                if(waterfinishtime<landStartTime[j]){ // waterride has finished before landride starts
                    tempfinishtime = landStartTime[j] + landDuration[j];
                }else{
                    tempfinishtime = waterfinishtime + landDuration[j];
                }
                finaltime = min(finaltime, tempfinishtime);
            }
        }
        return finaltime;
    }
};

class Solution2 {
public:
    int finishtime(vector<int> &start1, vector<int>& duration1, vector<int>& start2, vector<int>& duration2){
        int finish1 = INT_MAX;
        int finish2 = INT_MAX;
        for(int i=0; i<start1.size(); i++){
            finish1 = min(finish1, start1[i]+duration1[i]);
        }
        for(int i=0; i<start2.size(); i++){
            finish2 = min(finish2, max(finish1, start2[i])+duration2[i]);
        }
        return finish2;
    }
    int earliestFinishTime2(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int result1 = finishtime(landStartTime, landDuration, waterStartTime, waterDuration); // start with land ride
        int result2 = finishtime(waterStartTime, waterDuration, landStartTime, landDuration); // start with water ride

        return min(result1, result2);
    }
};