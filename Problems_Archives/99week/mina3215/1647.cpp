#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, M; // 집 개수, 길 개수
int visited[100002]; // 확인 및 유지비 기록


int main() {
	cin >> N >> M;
	
	priority_queue<pair<int, int>> q;
	vector<vector<pair<int,int>>> branch(N+1); //유지비, 도착 점

	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		branch[A].push_back({ C,B });
		branch[B].push_back({ C,A });
	}

	int start = 1;
	visited[start] = 1;
	for (int i = 0;i < branch[start].size();i++) {
		int C = branch[start][i].first;
		int next = branch[start][i].second;
		q.push({ -C,next });
	}

	int minu = 0;
	int ans = 0;

	while (!q.empty()){
		int C = -q.top().first;
		int start = q.top().second;
		q.pop();
		if (visited[start])continue;
		visited[start] = 1;
		ans += C;
		minu = max(minu, C);
		for (int i = 0;i < branch[start].size();i++) {
			int c = branch[start][i].first;
			int next = branch[start][i].second;
			if (visited[next])continue;
			q.push({ -c,next });
		}
	}

	cout << ans - minu;

}