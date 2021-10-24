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
using namespace chrono;
int n;
int cost[501];//각 파일별 비용
int sum[501];//해당 파일까지의 합
int dp[501][501];//a~b까지의 결과
int inf = 1000000000;//초기화값

//입력
void input(){
    for(int i=1;i<=n;i++){
        cin>>cost[i];
        sum[i] = sum[i-1]+cost[i];//각 파일의 합구하기
    }
}

//초기화
void init(){
    for(int i=1;i<=n;i++){
        cost[i] = 0;
        sum[i] = 0;
    }
}

//파일 합치기
void file_merge(){
    //점화식
    for(int i=1;i<=n;i++){//구하는 범위
        for(int j=1;j<=n-i;j++){//합치는 범위의 시작부분
            dp[j][i+j] = inf;//j~i+j
            for(int k=j;k<i+j;k++){
                dp[j][i+j] = min(dp[j][i+j],dp[j][k]+dp[k+1][i+j]+sum[i+j]-sum[j-1]);
            }
        }
    }
    //출력
    cout<<dp[1][n]<<"\n";
}

int main(){
    cin.tie(0);
    cout.tie(0);
     
    int test;
    cin>>test;
    for(int t=0;t<test;t++){
        cin>>n;
        init();//초기화
        input();//입력
        file_merge();//파일합치기
    }
    return 0;
}
