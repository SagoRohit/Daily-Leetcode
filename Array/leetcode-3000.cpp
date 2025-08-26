#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    int areaOfMaxDiagonal(std::vector<std::vector<int>>& dim) {
        double max_dig = -1.0;
        int max_area = -1;

        for (const auto& d : dim) {
            int length = d[0];
            int width = d[1];
            double diagonal_sq = static_cast<double>(length * length + width * width);
            double diagonal = sqrt(diagonal_sq);
            int area = length * width;

            if (diagonal > max_dig) {
                max_dig = diagonal;
                max_area = area;
            } else if (diagonal == max_dig) {
                if (area > max_area) {
                    max_area = area;
                }
            }
        }
        return max_area;
    }
};