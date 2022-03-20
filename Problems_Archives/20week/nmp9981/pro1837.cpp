#include <vector>
#include <algorithm>
using namespace std;

const int inf = 1e+8;
const int maxi = 201;
int dp[maxi][maxi];//i일때 j로 바꾸는 최소횟수 

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    //인접리스트 작성
    vector<vector<int>> dp(k,vector<int>(n+1,inf));//초기화
    vector<vector<int>> adj(n+1,vector<int>());
    for(int i=0;i<m;i++){
        int from = edge_list[i][0];
        int to = edge_list[i][1];
        //양방향 그래프
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    dp[0][gps_log[0]] = 0;//초기 연결, 바꾸는 횟수 0
    //gps_log의 2번째부터
    for(int i=1;i<k;i++){
        //i번째 자리가 j일때 
        for(int j=1;j<=n;j++){
            //j에서 인접노드로 이동
            for(int x=0;x<adj[j].size();x++){
                int next = adj[j][x];//다음 지점
                int alpha = 0;
                //경로가 변경되었는가?
                if(gps_log[i]!=next) alpha = 1;
                //최소횟수 갱신
                dp[i][next] = min(dp[i][next],dp[i-1][j]+alpha);
            }
        }
    }
    
    int answer = 0;
    //횟수가 존재하는가?
    if(dp[k-1][gps_log[k-1]]<inf) answer = dp[k-1][gps_log[k-1]];
    else answer = -1;
    return answer;
}
