#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

int n;
const int maxi = 17;//최대 맵 사이즈
int pipe[maxi][maxi];//파이프
int dp[4][maxi][maxi];//방법의 수(모양, 위치)
//1:가로, 2:세로, 3:대각선

//입력
void input(){
    cin>>n;
    memset(dp,0,sizeof(dp));//초기화
    //입력
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>pipe[i][j];
        }
    }
}

//파이프 옮기기
void move(){
    //맨 윗줄
    dp[1][1][2] = 1;//1,2는 가로 1
    for(int j=3;j<=n;j++){
        if(pipe[1][j]==0){//벽이 아닌 부분만
            dp[1][1][j] = dp[1][1][j-1];
        }
    }
    //점화식
    for(int i=2;i<=n;i++){
        for(int j=3;j<=n;j++){
            //가로
            if(pipe[i][j-1]==0 && pipe[i][j]==0){
                dp[1][i][j] = dp[1][i][j-1]+dp[3][i][j-1];
            }
            //세로
            if(pipe[i-1][j]==0 && pipe[i][j]==0){
                dp[2][i][j] = dp[2][i-1][j]+dp[3][i-1][j];
            }
            //대각선
            if(pipe[i-1][j]==0 && pipe[i][j-1]==0 && pipe[i][j]==0 && pipe[i-1][j-1]==0){
                dp[3][i][j] = dp[1][i-1][j-1]+dp[2][i-1][j-1]+dp[3][i-1][j-1];
            }
        }
    }
    //결과
    cout<<dp[1][n][n]+dp[2][n][n]+dp[3][n][n];
}

int main(){
    input();//입력
    move();//파이프 옮기기
    return 0;
}
