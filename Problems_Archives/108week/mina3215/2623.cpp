#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int N,M; 
int priority[1002];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	int T;
	vector<int> v[1002];

	fill(priority, priority + 1002, 0);

	for (int i = 0; i < M; i++) {
		cin >> T;
		vector<int> test;
		int p;
		// 입력 받고, 저장
		for (int j = 0; j < T;j++) {
			cin >> p;
			test.push_back(p);
		}
		for (int j = 0; j < T; j++) {
			for (int k = j + 1; k < T; k++) {
				v[test[j]].push_back(test[k]);
				priority[test[k]]++;
			}
		}
	}

	queue<int> q;

	for (int i = 1; i <= N; i++) {
		if (!priority[i]) q.push(i);
	}

	vector<int> ans;

	while (!q.empty()) {
		int now = q.front();
		ans.push_back(now);
		q.pop();
		for (int i = 0; i < v[now].size();i++) {
			priority[v[now][i]]--;
			if (priority[v[now][i]] == 0) q.push(v[now][i]);
		}
	}

	if (ans.size() == N) {
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i]<<'\n';
	}
	else
		cout << 0;

}