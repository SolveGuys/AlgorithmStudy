#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int v, e, k;
const int maxi = 20001;
const int inf = 1000000000;
vector<pair<int, int>> world[maxi];//그래프
int dist[maxi];//각 정점에서의 거리

//입력
void input() {
	cin >> v >> e;//정점,간선 개수
	cin >> k;//시작 정점
	for (int i = 0; i < e; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		world[a].push_back({ b,d });//지점,거리
	}
}
//다익스트라 알고리즘
void dijk(int start) {
	//거리 초기화
	for (int i = 1; i <= v; i++) dist[i] = inf;

	//처음값 저장
	dist[start] = 0;
	priority_queue<pair<int, int>> pq;//최대힙
	pq.push({ 0,start });//거리, 정점

	while (!pq.empty()) {
		int x = pq.top().second;//정점
		int xDist = -pq.top().first;//거리
		pq.pop();

		//이전 거리보다 더 크다면
		if (dist[x] < xDist) continue;

		//이웃탐색
		for (int i = 0; i < world[x].size(); i++) {
			int next = world[x][i].first;//지점
			int nextDist = world[x][i].second;//거리

			//더 작은 거리가 나오면
			if (dist[next] > xDist + nextDist) {
				dist[next] = xDist + nextDist;
				pq.push({ -dist[next],next });
			}
		}
	}
}
//출력
void output() {
	for (int i = 1; i <= v; i++) {
		if (dist[i] >= inf) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	dijk(k);//k지점부터
	output();//출력
	return 0;
}
