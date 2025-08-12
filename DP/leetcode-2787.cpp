#include<iostream>
#include<vector>
#include<math.h>
#include <cstring>
using namespace std;
class Solution {
public:
    int t[301][301];
    int m = 1e9+7;
    int solve(int n, int num, int x){
        if(n==0)
            return 1;
        if(n<0)
            return 0;
        int power = pow(num, x);
        if(power>n)
            return 0;
        
        if(t[n][num]!=-1)
            return t[n][num];
        int take = solve(n-power, num+1, x);
        int skip = solve(n, num+1, x);

        return t[n][num]=(take+skip)%m;
    }
    int numberOfWays(int n, int x) {
        memset(t, -1, sizeof(t)); 
        return solve(n, 1, x);
    }
};  
