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

int n;
int score[1001];//학생들 점수
int dp[1001][1001];//i~j까지의 결과

//입력
void input(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int s;
        cin>>s;
        score[i] = s;
    }
}

//위상정렬
void group(){
    //초기화
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = abs(score[j]-score[i]);
        }
    }
    
    for(int i=2;i<=n;i++){//구하는 범위의 길이
        for(int j=1;j<=n-i;j++){//시작하는 위치
            //j~i+j => j~k / k+1~i+J
            for(int k=j;k<i+j;k++){
                dp[j][i+j] = max(dp[j][i+j],dp[j][k]+dp[k+1][i+j]);
            }
        }
    }
    cout<<dp[1][n];//출력
}

int main(){
    cin.tie(0);
    cout.tie(0);

    input();//입력
    group();//조짜기
    return 0;
}
