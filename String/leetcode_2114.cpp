#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
    public:
        int spacecount(string s){
            int count=0;
            for(int i=0; i<s.size(); i++){
                if(s[i]==' ')
                    count++;
            }
            return count;
        }
        int mostWordsFound(vector<string>& sentences) {
            int max=0;
            for(int i=0; i<sentences.size(); i++){
                int cont = spacecount(sentences[i]);
                if(cont>max)
                    max= cont;
            }
            return max+1;
        }
    };
int main(){

    return 0;
}