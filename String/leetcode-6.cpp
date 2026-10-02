#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string convert(string s, int row) {
        if(row == 1)
            return s;
        int n = s.length();
        vector<bool> used (n,false);
        string ans = "";
        for(int iteration=row; iteration>0; iteration--){
            int jump = (iteration-1)*2;
            int start = row - iteration;
            if(jump == 0)
                break;
            for(int ind = start; ind < n; ind+=jump){
                if(used[ind]) continue;
                ans += s[ind];
                used[ind]=true;
            }
        }
        int jump = (row-1)*2;
        for(int i= (row-1); i<n; i+=jump){
            if(used[i])
                continue;
            ans += s[i];
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "A";
    cout<<sol.convert(s, 3)<<endl;
    return 0;
}