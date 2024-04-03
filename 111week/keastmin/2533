#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> graph[1000001];
vector<bool> visited;
int res = 0;

int dfs(int cur) {
	visited[cur] = true;

	int child[2] = { 0, 0 };

	for (const auto g : graph[cur]) {
		if (!visited[g]) {
			child[dfs(g)]++;
		}
	}

	if (child[0]) {
		res++;
		return 1;
	}

	return 0;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;
	visited.resize(N + 1, false);

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1);
	cout << res << '\n';

	return 0;
}
