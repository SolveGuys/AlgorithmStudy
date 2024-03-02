#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int visited[100002];
int max_v=0, x=0;

void DFS(int n, int ans, vector<vector<pair<int, int>>>& edges) {
	for (int i = 0; i < edges[n].size(); i++) {
		int b = edges[n][i].first;
		int v = edges[n][i].second;
		if (visited[b]) continue;
		visited[b] = 1;
		DFS(b, ans + v, edges);
		visited[b] = 0;
	}
	if (max_v < ans) {
		x = n;
		max_v = ans;
	}
}


int main() {
	cin >> N;
	vector <vector<pair<int, int>>> edges(N+1);
	for (int i = 0; i < N; i++) {
		int a,b,v;
		cin >> a;
		while (1) {
			cin >> b;
			if (b == -1) break;
			cin >> v;
			edges[a].push_back({b,v});
		}
	}
	visited[1] = 1;
	
	DFS(1,0,edges);

	fill(visited, visited + 100002, 0);
	visited[x] = 1;
	DFS(x, 0, edges);
	cout << max_v;

}