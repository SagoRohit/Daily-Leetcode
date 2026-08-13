#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        for(int i=0; i<n; i++){
            if(citations[i] >= n-i) // (n-i) means the paper coming after that
                return n-i; // so if, citations count is greater than (n-i) [paper count]
                // then our ans is (n-i). because, h-index condition was to have h papers with at least h-citations
        }
        return 0;
    }
};