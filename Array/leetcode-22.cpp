#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        dfs(0, 0, "", n, result);
        return result;
    }

private:
    void dfs(int openp, int closep, string s, int n, vector<string> &result)
    {
        if (openp == closep && closep + openp == 2 * n)
        {
            result.push_back(s);
            return;
        }
        if (openp < n)
        {
            dfs(openp + 1, closep, s + "(", n, result);
        }
        if (closep < openp)
        {
            dfs(openp, closep + 1, s + ")", n, result);
        }
    }
};