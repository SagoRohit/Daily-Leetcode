#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> checkLCP(string &word){
        int n= word.length();
        vector<vector<int>> lcp(n, vector<int>(n, 0));
        for(int i=0; i<n; i++){
            if(word[i]==word[n-1])
                lcp[i][n-1]=1;
            else
                lcp[i][n-1]=0;
        }
        for(int j=0; j<n; j++){
            if(word[j]==word[n-1])
                lcp[n-1][j]=1;
            else
                lcp[n-1][j]=0;
        }
        for(int i=n-2; i>=0; i--){
            for(int j=n-2; j>=0; j--){
                if(word[i]==word[j])
                    lcp[i][j]= 1 + lcp[i+1][j+1];
                else
                    lcp[i][j]=0;
            }
        }
        return lcp;
    }
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string word(n, '$');

        // making the word string
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(lcp[i][j]!=0){ // so there is a matching
                    word[i]= word[j];
                    break;
                }
            }
            if(word[i]=='$'){ // still we can't fill the word[i]
                vector<int> forbidden(26, false); // array of the alphabets if they are use or not
                // T- used, F-not used
                for(int j=0; j<i; j++){
                    if(lcp[j][i]==0)
                        forbidden[word[j]-'a']= true;
                }

                for(int idx=0; idx<26; idx++){
                    if(forbidden[idx]==false){
                        word[i]= idx+'a';
                    }
                }

                if(word[i]=='$')
                    return "";  // we could never build the string
            }
        }
        return checkLCP(word) == lcp? word:"";
    }
};
int main(){

    return 0;
}