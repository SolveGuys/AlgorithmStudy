#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int ans = 0;
	vector<vector<int>> Node(N+1);
	vector<int> friends(N + 1);
	vector<int> adopter(N + 1,0);
	queue<int> q;
	for (int i = 1; i < N; i++) {
		int u, v;
		cin >> u >> v;
		Node[u].push_back(v);
		Node[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) {
		friends[i] = Node[i].size();
		if (friends[i] == 1)
			q.push(i);
	}
	while (!q.empty()) {
		int n = q.front();
		q.pop();
		
		// 이미 friends가 0인 경우
		if (!friends[n]) continue;

		if (adopter[n]) {
			for (int i = 0; i < Node[n].size();i++) {
				int next = Node[n][i];
				if (friends[next]) {
					friends[next]--;
					friends[n]--;
					if (friends[next]==1)
						q.push(next);
				}
			}
		}
		else{
			for (int i = 0; i < Node[n].size();i++) {
				int next = Node[n][i];
				if (friends[next]) {
					friends[n]--;
					friends[next]--;
					if (!adopter[next]) {
						adopter[next] = 1;
						ans++;
					}
					if (friends[next] == 1) {
						q.push(next);
						
					}
				}
			}
		}

	}
	cout << ans;
}