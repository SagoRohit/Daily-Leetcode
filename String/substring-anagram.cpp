#include<iostream>
#include<string>
using namespace std;
bool substringanagram(string s1, string s2){
    int arr1[26] , arr2[26];

    // populate both array with freq
    for(int i=0; i<s2.length(); i++){
        arr1[s1[i]-'a']++;
        arr2[s2[i]-'a']++;
    }
    int l =0, r = s2.length();
    while(r<s1.length()){
        if(arr1 == arr2)
            return true;
        arr1[s1[l]-'a']--;
        arr2[s1[r]-'a']++;
        l++;
        r++;
    }
    return arr1==arr2;
}