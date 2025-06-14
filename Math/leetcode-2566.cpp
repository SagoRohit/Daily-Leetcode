#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
private:
    int changemaxdig(vector<int> &num)
    {
        int digit = 0;
        int i = 0;
        while (i < num.size() && num[i] == 9)
            i++;
        if (i == num.size())
            for (int j = 0; j < num.size(); j++)
                digit = digit * 10 + num[j];
        else
        {
            int grp = num[i];
            for (int j = 0; j < num.size(); j++)
            {
                if (num[j] == grp)
                    num[j] = 9;
                digit = digit * 10 + num[j];
            }
        }
        return digit;
    }
    int changemindig(vector<int> &num)
    {
        int digit = 0;
        int i = 0;
        int grp = num[i];
        while (i < num.size())
        {
            if (num[i] == grp)
            {
                num[i] = 0;
            }
            digit = digit * 10 + num[i];
            i++;
        }
        cout << "min: " << digit << endl;
        return digit;
    }
    void extractdig(vector<int> &maxi, int num)
    {
        while (num)
        {
            maxi.push_back(num % 10);
            num /= 10;
        }
    }

public:
    int minMaxDifference(int num)
    {
        vector<int> maxnum;
        extractdig(maxnum, num);
        reverse(begin(maxnum), end(maxnum));

        int d1 = changemaxdig(maxnum);

        vector<int> minum;
        extractdig(minum, num);
        reverse(begin(minum), end(minum));

        int d2 = changemindig(minum);

        return d1 - d2;
    }
};
int main()
{
    Solution sol;
    cout << sol.minMaxDifference(11891);
    return 0;
}