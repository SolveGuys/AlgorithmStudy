#include <iostream>
using namespace std;

int n,k,next_cnt;
const int maxi = 10;
const int inf = 1e+8;
int ans = inf;
int planet[maxi][maxi];//행성간 거리
int dp[maxi][maxi];//행성간 최단거리
bool visit[maxi];//행성 방문 여부

//입력
void input() {
	cin >> n>>k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> planet[i][j];
			//초기값
			if (i == j) dp[i][j] = 0;
			else dp[i][j] = inf;
		}
	}
}

//플로이드 알고리즘
void floyd() {
	for (int k = 0; k < n; k++) {//경유지점
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j] = min(dp[i][j], planet[i][k] + planet[k][j]);//그냥이 더 이득인가? 점k를 거치는것이 더 이득인가?
			}
		}
	}
}
//행성방문
void dfs(int x,int cnt,int sum) {
	//모두 방문
	if (cnt == n) {
		ans = min(ans, sum);
		return;
	}
	//다음지점
	for (int i = 0; i < n; i++) {
		//미방문 행성이면
		if (visit[i] == false) {
			visit[i] = true;
			int next = sum + dp[x][i];//비용
			dfs(i, cnt+1, next);
			visit[i] = false;
		}
	}
}
int main() {
	input();//입력
	floyd();//플로이드 알고리즘
	visit[k] = true;//방문 체크
	dfs(k,1,0);//행성k부터 방문
	cout << ans;//출력
	return 0;
}
