#include <iostream>
#include <algorithm>
using namespace std;

int a,b,c;
const int maxi = 3001;
string x,y;
int dp[maxi][maxi];//i,j까지의 결과

//입력
void input(){
    cin>>a>>b>>c;
    cin>>x>>y;
}

//점수
void score(){
    int n = x.size();
    int m = y.size();
    //초기값
    dp[0][0] = 0;
    for(int i=1;i<=n;i++){
        dp[i][0] = i*b;
    }
    for(int i=1;i<=m;i++){
        dp[0][i] = i*b;
    }
    //둘다선택? 또는 위 or 아래 선택
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            //문자열이 같다면
            if(x[i-1]==y[j-1]){//문자열은 0번부터 시작
                dp[i][j] = max({dp[i-1][j]+b,dp[i][j-1]+b,dp[i-1][j-1]+a});
            }else{
                dp[i][j] = max({dp[i-1][j]+b,dp[i][j-1]+b,dp[i-1][j-1]+c});
            }
        }
    }
    cout<<dp[n][m];//출력
}
int main(){
    input();//입력
    score();//점수
    return 0;
}
