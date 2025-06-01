#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    using ll = long long;
    long long distributeCandies(int n, int limit) {
        ll result=0;
        ll ch1min = max(0, n- 2*limit);
        ll ch1max = min(n, limit);
        for(int i=ch1min; i<=ch1max; i++)
        {
            int N = n-i; // for ch2 and ch3
            ll ch2max= min(N, limit);
            ll ch2min = max(0, N-limit);

            result+= (ch2max-ch2min+1);
        }
        return result;
    }
};