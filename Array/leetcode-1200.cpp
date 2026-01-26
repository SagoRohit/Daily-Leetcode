#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int mindiff=INT_MAX;
        for(int i=0; i<arr.size()-1; i++){
            mindiff= min(mindiff, abs(arr[i+1]-arr[i]));
        }
        vector<vector<int>> result;
        for(int i=0; i<arr.size()-1; i++){
            if(mindiff+arr[i]==arr[i+1])
                result.push_back({arr[i],arr[i+1]});
        }
        return result;
    }
};