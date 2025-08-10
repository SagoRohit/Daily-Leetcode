#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string base = to_string(n);
        // cout<<base<<endl;
        sort(base.begin(), base.end());
        // cout<<base<<endl;
        for(int i=0; i<31; i++)
        {
            int leftshift = 1 << i;
            string temp = to_string(leftshift);
            cout<<temp<<endl;
            sort(begin(temp), end(temp));
            // cout<<temp<<endl;
            if(base==temp)
                return true;
        }
        return false;
    }
};
int main(){
    Solution sol;
    cout<<sol.reorderedPowerOf2(46)<<endl;
    return 0;
}