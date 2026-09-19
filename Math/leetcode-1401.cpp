#include<iostream>
#include<math.h>
using namespace std;
class Solution {
public:
    double dist(int x, int y, int x1, int y1){
        return sqrt(pow(abs(x-x1),2) + pow(abs(y-y1),2));
    }
    bool checkOverlap(int r, int x, int y, int x1, int y1, int x2, int y2) {
        if(x < x1 and r < (x1-x))
            return false;
        if(x2 < x and (x-x2) > r)
            return false;
        if(y > y2 and r < (y-y2))
            return false;
        if(y < y1 and r < (y1-y))
            return false;
        if(x < x1 and y < y1 and dist(x,y,x1,y1) > r)
            return false;
        if(x < x1 and y > y2 and dist(x,y,x1,y2) > r)
            return false;
        if(x > x2 and y < y1 and dist(x,y,x2,y1) > r)
            return false;
        if(x > x2 and y > y2 and dist(x,y,x2,y2) > r)
            return false;
        return true;
    }
};
int main(){
    Solution sol;
    cout<<sol.checkOverlap(1415, 807, -784, -733, 623, -533, 1005)<<endl;;
    return 0;
}