#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int start) {
        int n = words.size();
        for(int i=0; i<=n >>1; i++){
            if(words[(start+i)%n]==target or words[(start-i+n)%n]==target)
                return i; 
        }
        return -1;
    }
};
int main(){
    Solution sol;
    vector<string> vec = {"i","eat","leetcode"};
    string target = "ate";
    int start = 0;
    cout<<sol.closestTarget(vec, target, start);
    return 0;
}