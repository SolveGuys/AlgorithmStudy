#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <chrono>
#include <stack>
#include <queue>
#include <deque>
#include <utility>

using namespace std;//이름공간 선언
int n,m;
const int maxi = 50001;
int guest[maxi];
int dp[4][maxi];//i번호의 차에서 j까지 
int sum[maxi];//누적합

//입력
void input(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>guest[i];
        sum[i] = sum[i-1]+guest[i];//누적합구하기
    }
    cin>>m;
}

//손님운송
void train(){
    for(int i=1;i<=3;i++){
        for(int j=m;j<=n;j++){
            dp[i][j] = max(dp[i][j-1],dp[i-1][j-m]+sum[j]-sum[j-m]);
        }
    }
    cout<<dp[3][n];
}

int main(){
    cin.tie(0);
    cout.tie(0);

    input();//입력
    train();//손님운송
    return 0;
}
