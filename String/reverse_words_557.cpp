/*557. Reverse Words in a String III
Easy
                        <-- Problem Statement -->
Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

 

Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Example 2:

Input: s = "Mr Ding"
Output: "rM gniD"
 

Constraints:

1 <= s.length <= 5 * 104
s contains printable ASCII characters.
s does not contain any leading or trailing spaces.
There is at least one word in s.
All the words in s are separated by a single space.
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        int i=0, j=0;
        string temp ="";
        string result = "";
        for(char ch: s){
            if(ch!=' '){
                temp.push_back(ch);
            }else{
                reverse(temp.begin(), temp.end());
                result.append(temp);
                result.push_back(' ');
                temp="";
            }
        }
        reverse(temp.begin(), temp.end()); 
        result.append(temp);  
        return result;      
    }
};
