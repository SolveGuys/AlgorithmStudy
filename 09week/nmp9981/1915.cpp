#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;//이름공간 선언

int n,m;
const int maxi = 1002;
int dp[maxi][maxi];//각 지점까지의 최대 정사각형의 넓이

//입력하기
void input(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string s;//문자열로 입력받음
        cin>>s;
        for(int j=1;j<=m;j++){
            dp[i][j] = s[j-1]-48;//아스키코드 이용
        }
    }
}

//최대 정사각형의 넓이
void square(){
    int max_s = 0;//최댓값
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(dp[i][j] != 0){//정사각형 지점
                //가장 넓이가 작은 정사각형 기준으로 연장
                dp[i][j] = min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]})+1;
            }
            max_s = max(max_s,dp[i][j]);//갱신
        }
    }
    cout<<pow(max_s,2);
}

int main(){
    //빠른 입출력
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();//입력
    square();//정사각형 최대 넓이 구하기
    return 0;
}
