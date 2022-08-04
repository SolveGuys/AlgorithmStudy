#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,m,start,last;
const int maxi = 1001;
const int inf = 100000001;
int cost[maxi];//비용
vector<pair<int,int>> bus[maxi];//버스 노선

//입력
void input() {
	cin >> n>>m;
	for (int i = 0; i < m; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		bus[a].push_back({ b,d });
	}
	cin >> start >>last;
}

//다익스트라(최소 비용)
void Dijk(int start,int last) {
	//거리 초기화
	for (int i = 1; i <= n; i++) cost[i] = inf;

	//시작점 넣기
	cost[start] = 0;
	priority_queue<pair<int, int>> pq;//최대힙
	pq.push({ 0,start });//비용, 정점

	while (!pq.empty()) {
		int fee = -pq.top().first;//비용, 작은것부터
		int node = pq.top().second;//정점
		pq.pop();

		//더 큰비용이 오면 패스
		if (fee > cost[node]) continue;

		//이웃탐색
		for (int i = 0; i < bus[node].size(); i++) {
			int nextNode = bus[node][i].first;
			int nextCost = bus[node][i].second;
			//더 적은 비용이 오면 갱신
			if (fee + nextCost < cost[nextNode]) {
				cost[nextNode] = fee + nextCost;
				pq.push({ -cost[nextNode],nextNode });//비용이 적은것이 더 우선이므로 -1을 곱했다
			}
		}
	}
	cout << cost[last];//출력
}

int main(){
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	Dijk(start,last);//다익스트라
    return 0;
}
