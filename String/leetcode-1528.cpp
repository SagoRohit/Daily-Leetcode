#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        string restoreString(string s, vector<int>& indices) {
            string t = s;
            for(int i=0; i<indices.size(); i++){
                s[indices[i]]=t[i];
            }
            return s;
        }
    };