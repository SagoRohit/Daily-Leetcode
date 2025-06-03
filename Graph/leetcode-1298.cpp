#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution
{
public:
    int maxCandies(vector<int> &status, vector<int> &candies, 
        vector<vector<int>> &keys, vector<vector<int>> &containedBoxes, vector<int> &initialBoxes)
    {
        int collectedCandies=0;
        unordered_set<int> visited;
        unordered_set<int> foundboxes;

        queue<int> pq;
        for(int &boxes: initialBoxes)
        {
            foundboxes.insert(boxes);
            if(status[boxes]==1)
            {
                pq.push(boxes);
                visited.insert(boxes);
                collectedCandies += candies[boxes]; 
            }
            
        }

        while(!pq.empty())
        {
            int box = pq.front();
            pq.pop();

            for(int &insidebox: containedBoxes[box])
            {
                foundboxes.insert(insidebox);
                if(status[insidebox]==1 && !visited.count(insidebox)){
                    pq.push(insidebox);
                    visited.insert(insidebox);
                    collectedCandies+= candies[insidebox];
                }
            }

            for(int &boxKey: keys[box])
            {
                status[boxKey]=1;
                if(foundboxes.count(boxKey) && !visited.count(boxKey))
                {
                    pq.push(boxKey);
                    visited.insert(boxKey);
                    collectedCandies+= candies[boxKey];
                }
            }
        }
        return collectedCandies;
    }
};