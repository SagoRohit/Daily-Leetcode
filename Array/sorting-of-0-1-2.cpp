#include<iostream>
#include<vector>
using namespace std;
void sortcolor(vector<int> &nums){
    int low=0, mid=0;
    int high = nums.size()-1;
    while(mid<=high){
        if(nums[mid]==0){
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }else if(nums[mid]==1){
            mid++;
        }else{
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}
void print(vector<int> &num){
    for(int n: num){
        cout<<n<<" ";
    }
}
int main(){
    vector<int> arr = {2,1,1,2,0,0};
    sortcolor(arr);
    print(arr);
    return 0;
}