#include <iostream>
using namespace std;
typedef long long ll;

const int maxi = 5001;
const ll mod = 1000000007;
ll dp[maxi];//괄호 경우의 수

//괄호의 경우의 수
void parenthesis(){
    dp[0] = 1;
    dp[2] = 1;
    dp[4] = 2;
    for(int i=6;i<maxi;i+=2){
        for(int j=0;j<=i-2;j+=2){
            dp[i] += dp[j]*dp[i-j-2];//int 범위 초과
            dp[i] %= mod;
        }
    }
}

int main(){
    int test,n;
    parenthesis();//괄호 경우의 수
    cin>>test;
    for(int t=0;t<test;t++){
        cin>>n;
        if(n%2==1){//홀수일 경우에는 존재하지 않는다.
            cout<<0<<"\n";
        }else{
            cout<<dp[n]<<"\n";
        }
    }
    return 0;
}
