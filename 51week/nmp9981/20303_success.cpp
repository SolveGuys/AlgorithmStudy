#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, k,child,candySum;
const int maxi = 30001;
const int kmaxi = 3001;
vector<int> graph[maxi];//친구 관계
int candy[maxi];//사탕 개수
int visit[maxi];//방문여부
vector<int> getCandy;//얻은 사탕 수
vector<int> getHuman;//뺏은 인원 수
int dp[maxi][kmaxi];//i번까지 했을때 j인원의 사탕 개수 

//max
inline int max(int x, int y) {
	return x > y ? x : y;
}
//입력
void input() {
	cin >> n >> m>>k;
	for (int i = 1; i <= n; i++) cin >> candy[i];//사탕 개수
	//그래프 입력
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);//양방향 그래프
		graph[b].push_back(a);
	}
}
//사탕 스틸
bool Steal(int st) {
	queue<int> q;
	q.push(st);
	visit[st] = true;//방문 체크
	
	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int j = 0; j < graph[node].size(); j++) {
			int next = graph[node][j];//다음 지점
			if (visit[next] == false) {//미방문인 지역만
				visit[next] = true;
				child++;
				candySum += candy[next];
				q.push(next);
			}
		}
	}
	if (child >= k) return false;//인원 초과
	return true;
}
//정산
void Account() {
	dp[0][getHuman[0]] = getCandy[0];//초기값
	for (int i = 1; i < getCandy.size(); i++) {//i번 묶음
		for (int j = 1; j < k; j++) {//인원 제한
			if (j < getHuman[i]) dp[i][j] = dp[i - 1][j];//그대로
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - getHuman[i]] + getCandy[i]);//선택 or 그대로
		}
	}
	cout << dp[getCandy.size() - 1][k - 1];
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	input();//입력
	//사탕 스틸
	for (int i = 1; i <= n; i++) {
		if (visit[i] == false) {
			child = 1; candySum = candy[i];//초기화
			//인원 내로 들어오는 경우만 넣는다.
			if (Steal(i)) {
				getCandy.push_back(candySum);
				getHuman.push_back(child);
			}
			else {
				getCandy.push_back(0);
				getHuman.push_back(0);
			}
		}
	}
	Account();//사탕 정산
	return 0;
}
