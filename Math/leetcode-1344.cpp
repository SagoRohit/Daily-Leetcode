#include<iostream>
#include<math.h>
using namespace std;
class Solution {
public:
    double angleClock(int hour, int minu) {
        double hrangle = hour * 30 + 0.5 * minu;
        double minangle = 6 * minu;
        double anglebet = abs(hrangle - minangle);
        return min(anglebet, 360-anglebet);
    }
};