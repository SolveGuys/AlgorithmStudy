#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> edge) {

	vector<vector<int>> node(n + 1);
	vector<int> check(n + 1);

	for (int i = 0; i < edge.size(); i++) {
		node[edge[i][0]].push_back(edge[i][1]);
		node[edge[i][1]].push_back(edge[i][0]);
	}

	queue<pair<int, int>> q;
	check[1] = 1;
	q.push({ 1,1 });
	int num = 0;
	int max_d = 0;
	int j, N;
	while (!q.empty()) {
		tie(j, N) = q.front();
		q.pop();
		if (N > max_d) {
			max_d = N;
			num = 1;
		}
		else if (N == max_d) {
			num += 1;
		}
		for (int i = 0; i < node[j].size(); i++) {
			if (node[j][i] && !check[node[j][i]]) {
				q.push({ node[j][i],N + 1 });
				check[node[j][i]] = 1;
			}
		}
	}

	return num;
}