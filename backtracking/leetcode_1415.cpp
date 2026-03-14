#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    /* void solve(int n, string curr, vector<string> &result){
        if(curr.length()==n){
            result.push_back(curr);
            return ;
        }
        for(char ch = 'a'; ch<= 'c'; ch++){
            if(curr.back()==ch)
                continue;
            curr.push_back(ch); // DO
            solve(n, curr, result); // EXPLORE
            curr.pop_back(); // UNDO
        }
    }
    string getHappyString(int n, int k) {
        string curr = "";
        vector<string> result;
        solve(n, curr, result);
        return result[k-1];
    }
    */

    // more optimized solution, the previous solution stores all the possible
    // strings in the vector, which is a waste of space.
    // so now we will just track the count and return the kth string.

    void solve(string &curr, int n, int &k, int &count, string &result){
        if(curr.length()==n){
            count++;
            if(count==k)
                result=curr;
            return;
        }
        for(char ch='a'; ch<='c'; ch++){
            if(!curr.empty() and curr.back()==ch)
                continue;
            curr.push_back(ch); // do
            solve(curr, n, k, count, result); //explore
            curr.pop_back(); //undo
        }
    }
    string getHappyString(int n, int k){
        string curr="";
        string result="";
        int count=0;
        solve(curr, n, k, count, result);
        return result;
    }
};
int main(){
    Solution sol;
    cout<<sol.getHappyString(3,9)<<endl;
    return 0;
}