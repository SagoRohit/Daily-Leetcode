/*520. Detect Capital
Easy
Topics
Companies
We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right.

 

Example 1:

Input: word = "USA"
Output: true
Example 2:

Input: word = "FlaG"
Output: false
 

Constraints:

1 <= word.length <= 100
word consists of lowercase and uppercase English letters.*/
#include<iostream>
#include<string>
#include<cctype>
using namespace std;
class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        bool a = false;
        if(isupper(word[0])){
            if(n>1 && isupper(word[1])){
                a=true;
            }
        }
        for(int i=1;i<n;i++){
            if(a==false){
                if(isupper(word[i])){
                    return false;
                }
            }
            else{
                if(islower(word[i])){
                    return false;
                }
            }
        }
        return true;
    }
};