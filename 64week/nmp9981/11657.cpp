#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int n,m,a,b,c;
const int maxi = 501;
const int inf = 1111111111;
bool isNegative;//사이클인가?
ll dist[maxi];//거리
vector<pair<int, int>> graph[maxi];//그래프

//초기화
void init() {
	for (int i = 0; i <= n; i++) dist[i] = inf;
}
//입력
void input() {
	cin >> n>>m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b>>c;
		graph[a].push_back({ b,c });//출발 지점->도착지점,비용
	}
	init();//초기화
}

//벨만 포드
void Bellman_Ford(int start) {
	dist[start] = 0;//시작 지점
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < graph[j].size(); k++) {
				int next = graph[j][k].first;
				int nextDist = graph[j][k].second;

				if (dist[j] == inf) continue;
				if (dist[next] > dist[j] + nextDist) {
					dist[next] = dist[j] + nextDist;
					if (i == n) isNegative = true;
				}
			}
		}
	}
	//출력
	if (isNegative) cout << -1 << "\n";//음수 사이클
	else {
		for (int i = 2; i <= n; i++) {
			if (dist[i] == inf) cout << -1 << "\n";
			else cout << dist[i] << "\n";
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();//입력
	Bellman_Ford(1);//벨만 포드 알고리즘
	return 0;
}
