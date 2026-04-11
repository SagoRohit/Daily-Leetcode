#include<iostream>
using namespace std;
void solve(int n){
    cout<<n<<" ";
    if(n<=0)
        return;
    solve(n-5);
    cout<<n<<" ";
}
int main(){
    solve(7);
    return 0;
}