#include <iostream>
#include <cstring>
using namespace std;

int n,t;
const int maxi = 101;
string max_dp[maxi];
string min_dp[maxi] = {
    "0","0","1","7","4","2","6","8","10","18","22","20"};

//최댓값
void max_num(){
    max_dp[2] = '1';max_dp[3] = '7';
    for(int i=4;i<maxi;i++){
        max_dp[i]=max_dp[i-2]+'1';
    }
}
//최솟값
void min_num(){
    for(int i=12;i<maxi;i++){
        min_dp[i] = min_dp[i-7]+'8';
        //예외
        if(i==17){
            min_dp[i]="200";
        }
    }
}
int main(){
    cin>>t;
    max_num();//최댓값
    min_num();;//최솟값
    while(t--){
        cin>>n;
        cout<<min_dp[n]<<" "<<max_dp[n]<<"\n";
    }
    return 0;
}
