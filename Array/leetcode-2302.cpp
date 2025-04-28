#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    using ll = long long;
    long long countSubarrays(vector<int> &nums, long long k)
    {
        ll count = 0, sum = 0, i = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            sum += nums[j];
            while (sum * (j - i + 1) >= k)
            {
                sum -= nums[i++];
            }
            count += (j - i + 1);
        }
        return count;
    }
};
int main()
{

    return 0;
}