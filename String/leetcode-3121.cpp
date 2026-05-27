#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> small (26,-1);
        vector<int> capital (26,-1);
        int count=0, i=0;
        // populating 2 arrays
        for(char c: word){
            if(c>='a' and c<='z'){
                small[c-'a']=i;
            }else{
                if(capital[c-'A']==-1){
                    capital[c-'A']=i;
                }
            }
            i++;
        }
        for(int i=0; i<26; i++){
            if(small[i]!=-1 and capital[i]!=-1 and small[i]<capital[i])
                count++;
        }
        return count;
    }
};