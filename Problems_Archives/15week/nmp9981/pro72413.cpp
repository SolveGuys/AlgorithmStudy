#include <string>
#include <vector>
using namespace std;

const int maxi = 201;
const int inf = 98765432;
int dp[maxi][maxi];

//초기화
void init(int n,vector<vector<int>> v){
    //초기화
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                dp[i][j] = 0;
            }else{
                dp[i][j] = inf;
            }
        }
    }
    //벡터 입력
    for(int i=0;i<v.size();i++){
        int c = v[i][0];
        int d = v[i][1];
        int f = v[i][2];
        dp[c][d] = f;
        dp[d][c] = f;
    }
}

//플로이드 알고리즘
void floyd(int n){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    init(n,fares);//초기화
    floyd(n);//플로이드 알고리즘
    //합승하기
    int answer = inf;
    for(int t=1;t<=n;t++){//어디서 내리는가?
        answer = min(answer,dp[s][t]+dp[t][a]+dp[t][b]);
    }
    return answer;
}
