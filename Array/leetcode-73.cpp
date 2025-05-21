class Solution {
public:
    void setZeroes(vector<vector<int>>& ma) {
        int m = ma.size();
        int n = ma[0].size();

        bool firstrow = false;
        bool firstcol = false;

        for(int i=0; i<n; i++){
            if(ma[0][i]==0){
                firstrow= true;
                break;
            }
        }

        for(int i=0; i<m; i++){
            if(ma[i][0]==0){
                firstcol = true;
                break;
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(ma[i][j]==0){
                    ma[i][0]=0;
                    ma[0][j]=0;
                }
            }
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(ma[i][0]==0 || ma[0][j]==0)
                    ma[i][j]=0;
            }
        }

        if(firstrow){
            for(int j=0; j<n; j++){
                ma[0][j]=0;
            }
        }
        if(firstcol){
            for(int i=0; i<m; i++){
                ma[i][0]=0;
            }
        }
    }
};