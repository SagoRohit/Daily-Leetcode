#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.length();
        int i = 0;
        int count = 0;
        while (i < n) {
            char curr = word[i];
            int j = 0;
            while (j < n && word[i] == curr) {
                i++;
                j++;
            }

            count += j - 1;
        }
        return count + 1;
    }
};