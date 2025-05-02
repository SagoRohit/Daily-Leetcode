#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        int n = dominoes.length();
        vector<int> leftclosestR(n);
        vector<int> rightclosestL(n);

        for(int i=0; i<n; i++){
            if(dominoes[i]=='R')
                leftclosestR[i]=i;
            else if(dominoes[i]=='.')
                leftclosestR[i]= i>0? leftclosestR[i-1]:-1;
            else
                leftclosestR[i]=-1; 
        }

        for(int i=n-1; i>=0; i--){
            if(dominoes[i]=='L')
                rightclosestL[i]=i;
            else if(dominoes[i]=='.')
                rightclosestL[i]= i<(n-1)? rightclosestL[i+1]: -1;
            else
                rightclosestL[i]=-1;
        }

        
        string result(n, ' ');
        for(int i=0; i<n; i++){
            int distL =  abs(i-rightclosestL[i]);
            int distR =  abs(i-leftclosestR[i]);

            if(leftclosestR[i]==rightclosestL[i])
                result[i]='.';
            else if(leftclosestR[i]==-1)
                result[i]='L';
            else if(rightclosestL[i]==-1)
                result[i]= 'R';
            else if(distL==distR)
                result[i]= '.';
            else 
                result[i] = distR<distL? 'R':'L';
        }
        return result;
    }
    
};
int main()
{

    return 0;
}