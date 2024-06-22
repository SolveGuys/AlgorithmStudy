#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<bool>> graph;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	graph.resize(N + 1, vector<bool>(N + 1, false));
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = true;
	}

	//cout << '\n';
	//for (int i = 1; i <= N; i++) {
	//	for (int j = 1; j <= N; j++) {
	//		if (graph[i][j])
	//			cout << 'T' << ' ';
	//		else
	//			cout << 'F' << ' ';
	//	}
	//	cout << '\n';
	//}

	// 플로이드 워셜
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (graph[i][k] && graph[k][j]) {
					graph[i][j] = true;
				}
			}
		}
	}

	//cout << '\n';
	//for (int i = 1; i <= N; i++) {
	//	for (int j = 1; j <= N; j++) {
	//		if (graph[i][j])
	//			cout << 'T' << ' ';
	//		else
	//			cout << 'F' << ' ';
	//	}
	//	cout << '\n';
	//}

	int res = 0;
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (graph[i][j] || graph[j][i]) cnt++;
		}
		if (cnt == N - 1) {
			res++;
		}
	}

	cout << res << '\n';

	return 0;
}
