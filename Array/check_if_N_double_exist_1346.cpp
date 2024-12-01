/* 1346. Check If N and Its Double Exist 

Easy - Marked
           <-- Problem Statement -->

Given an array arr of integers, check if there exist two indices i and j such that :

i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]

Example 1:

Input: arr = [10,2,5,3]
Output: true
Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]
Example 2:

Input: arr = [3,1,7,11]
Output: false
Explanation: There is no i and j that satisfy the conditions.
 

Constraints:

2 <= arr.length <= 500
-103 <= arr[i] <= 103


            <-- Solution Approach -->

==> Build a HashTable (Behind the reason is, finding something using hashTable is useful)
==> Then loop through the array a find the N*2
==> If found, then return true
==> And in the last return false
*/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // Build hashtable
        unordered_set<int> seen;
        for(int &num: arr){
            if(seen.count(num*2)||(num%2==0) && seen.count(num/2)>0)
                return true;
            seen.insert(num);   
        }
        return false;
    }
};
