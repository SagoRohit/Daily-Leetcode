#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int start = 0;
        int ans = 0;
        unordered_map<char, int> freq;
        for(int end=0; end<s.length(); end++){
            freq[s[end]]++; // add the char to map
            while(freq[s[end]]>2){
                freq[s[start]]--;
                start++;
            }
            ans = max(ans, end-start+1);
        }
        return ans;
    }
};
int main(){
    Solution sol;
    string s = "bcbbbcba";
    cout<<sol.maximumLengthSubstring(s);
    return 0;
}