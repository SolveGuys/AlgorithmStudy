#include <iostream>
using namespace std;

int n;
const int maxi = 1001;
int score[maxi];//학생 점수
int dp[maxi][maxi];//i~j까지의 결과

//입력
void input(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>score[i];
}
//조짜기
void Grouping(){
    //초기화
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            //두 값의 차이로 초기화
            dp[i][j] = abs(score[i]-score[j]);
        }
    }
    
    for(int i=2;i<=n;i++){//구하는 범위의 길이
        for(int j=1;j<=n-i;j++){//시작하는 위치
            //j~i+j => j~k / k+1~i+j
            for(int k=j;k<i+j;k++) dp[j][i+j] = max(dp[j][i+j],dp[j][k]+dp[k+1][i+j]);
        }
    }
    cout<<dp[1][n];//출력
}
int main()
{
    input();//입력
    Grouping();//조짜기
    return 0;
}
