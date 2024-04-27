#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define HAVE_PATH 1
#define HAVE_NO_PATH 0

int N, M;
vector<bool> visited;
vector<pair<int, int>> graph[10001];
int s, e;
int maxCost = 0;;
int res = 0;

// 기준이 되는 코스트보다 높은 코스트의 경로가 존재하는지 BFS를 통해 탐색
int BFS(int targetCost) {
	queue<int> q;
	q.push(s);
	visited[s] = true;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		if (curr == e) return HAVE_PATH;

		for (const auto& g : graph[curr]) {
			int next = g.first;
			int nextCost = g.second;

			// 기준이 되는 코스트보다 높은 코스트의 경로만 푸쉬
			if (!visited[next] && targetCost <= nextCost) {
				q.push(next);
				visited[next] = true;
			}
		}
	}

	return HAVE_NO_PATH;
}

// 이분 탐색을 통해 코스트의 최댓값 탐색
void BinarySearch() {
	int left = 0;
	int right = maxCost;

	while (left <= right) {
		visited.assign(N + 1, false);
		int mid = (left + right) / 2;
		if (BFS(mid) == 1) left = mid + 1;
		else right = mid - 1;

		// cout << left<<' ' << mid<<' '<<right << '\n';
	}

	res = right;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	// Input
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		// 양방향 그래프
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });

		// 최대 코스트를 알아놔야 이분 탐색 가능
		maxCost = max(maxCost, c);
	}

	// 시작과 끝 지점 
	cin >> s >> e;

	// Binary search and BFS
	BinarySearch();

	cout << res << '\n';

	return 0;
}
