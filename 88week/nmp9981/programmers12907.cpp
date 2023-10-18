#include <string>
#include <vector>
using namespace std;

const int maxi = 100001;
const int mod = 1000000007;
int dp[101][maxi];

//초기화
void Init(int n,vector<int> money){
    for(int j=0;j<=n;j++){
        if(j%money[0]==0) dp[0][j] =1;
    }
}
//거스름돈
int Change(int n,vector<int> money){
    for(int i=1;i<money.size();i++){
        for(int j=0;j<=n;j++){
            if(j<money[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = (dp[i-1][j]+dp[i][j-money[i]])%mod;
        }
    }
    return dp[money.size()-1][n];
}
int solution(int n, vector<int> money) {
    Init(n,money);//초기화
    return Change(n,money);
}
