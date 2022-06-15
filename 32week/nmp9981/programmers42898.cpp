#include <string>
#include <vector>
#include <cstring>
using namespace std;

const int maxi = 101;
const int mod = 1000000007;
int dp[maxi][maxi];

//초기화
void init(int m, int n, vector<vector<int>> puddles){
    memset(dp,0,sizeof(dp));
    //물 웅덩이
    for(int i=0;i<puddles.size();i++){
        dp[puddles[i][1]][puddles[i][0]] = -1;
    }
    //가장자리
    for(int i=1;i<=n;i++){
        if(dp[i][1]==-1) break;
        else dp[i][1] = 1;
    }
    for(int j=1;j<=m;j++){
        if(dp[1][j]==-1) break;
        else dp[1][j] = 1;
    }
}

int solution(int m, int n, vector<vector<int>> puddles) {
    init(m,n,puddles);//초기화
    int answer = 0;
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            if(dp[i][j]==-1) continue;//물웅덩이
            else if(dp[i-1][j]==-1) dp[i][j] = dp[i][j-1];//위 웅덩이
            else if(dp[i][j-1]==-1) dp[i][j] = dp[i-1][j];//왼쪽 웅덩이
            else dp[i][j] = (dp[i-1][j]+dp[i][j-1])%mod;//결과
        }
    }
    answer = dp[n][m]%mod;//나머지
    return answer;
}
