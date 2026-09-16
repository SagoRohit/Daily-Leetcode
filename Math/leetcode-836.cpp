class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0];
        int y1 = rec1[1];
        int x2 = rec1[2];
        int y2 = rec1[3];

        int x1_prime = rec2[0];
        int y1_prime = rec2[1];
        int x2_prime = rec2[2];
        int y2_prime = rec2[3];   

        if(x1 < x1_prime and x2 <= x1_prime)
            return false;
        if(x1_prime < x1 and x2_prime <= x1)
            return false;
        if(y1 < y1_prime and y2 <= y1_prime)
            return false;
        if(y1_prime < y1 and y2_prime <= y1)
            return false;
        return true;
    }
};
