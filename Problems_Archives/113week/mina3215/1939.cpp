#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;
typedef long long ll;

int N, M;
int S, E;

/*
* Dijkstra �˰��� ���
* �ִ븦 ��� ã�Ƽ� �̵�
* ���Ŀ� w �� ���� ������ ã��. 
*/

int Dijkstra(vector<vector<pair<int, ll>>> &v) {
	priority_queue<pair<ll, int>>pq;
	vector<int> visited(N + 1, 0);
	visited[S] = 2e9;
	for (auto i : v[S])
		pq.push({ i.second, i.first });
	while (!pq.empty()) {
		int prev;
		ll w;
		tie(w, prev) = pq.top();
		pq.pop();
		if (visited[prev]) continue;
		visited[prev] = w;
		if (prev == E) return visited[E];
		// i {����, ����ġ}
		for (auto i : v[prev]) {
			if (visited[i.first]) continue;
			// ���Ŀ� �߷� �� ���� ���� �� �Ѱ� ��.
			pq.push({ min(i.second, w), i.first });
		}
	}
	return visited[E];
}

int main() {
	cin >> N >> M;
	vector<vector<pair<int, ll>>> v(N+1);
	for (int i = 0; i < M; i++) {
		int A, B;
		ll C;
		cin >> A >> B >> C;
		v[A].push_back({ B,C });
		v[B].push_back({ A,C });
	}
	cin >> S >> E;
	
	cout << Dijkstra(v);
}