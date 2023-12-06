#include <string>
#include <vector>
using namespace std;

const int maxi = 101;
int dp[maxi][maxi];//경우의 수
const int mod = 1000000007;

//초기화
void init(int m,int n,vector<vector<int>>puddles){
    //물웅덩이
    for(int i=0;i<puddles.size();i++) dp[puddles[i][1]][puddles[i][0]] = -1;
    //가장자리
    for(int j=1;j<=m;j++){
        if(dp[1][j]==-1) break;
        dp[1][j] = 1;
    }
    for(int i=1;i<=n;i++){
        if(dp[i][1]==-1) break;
        dp[i][1] = 1;
    }
}
//경우의 수
int caseNum(int m,int n){
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            if(dp[i][j]==-1) continue;//물 웅덩이
            else if(dp[i-1][j]==-1) dp[i][j] = dp[i][j-1];//위 웅덩이
            else if(dp[i][j-1]==-1) dp[i][j] = dp[i-1][j];//왼쪽 웅덩이
            else dp[i][j] = (dp[i-1][j]+dp[i][j-1])%mod;
        }
    }
    return dp[n][m]%mod;
}
int solution(int m, int n, vector<vector<int>> puddles) {
    init(m,n,puddles);//초기화
    return caseNum(m,n);//경우의 수
}
