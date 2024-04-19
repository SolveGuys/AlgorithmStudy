#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int N, D = 0;
vector<pair<int, int>> v;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int p, d;
		cin >> p >> d;
		v.push_back({ d,p });
		D = max(D, d);
	}
	sort(v.begin(), v.end());

	// 이전 DP를 담을 q -> 메모리 초과 뜸;
	queue<vector<int>> q;

	// 처음 더미 생성.
	vector<int> dp(D + 1,0);
	q.push(dp);

	for (int i = 1; i <= N; i++) {
		int idx = i - 1;
		int d = v[idx].first;
		int p = v[idx].second;

		// 이전 기록 불러오기
		vector<int> prev = q.front();
		// 현재 최대 값을 기록할 DP
		vector<int> DP(D + 1,0);
		
		q.pop();

		for (int j = 1; j <= d; j++) {
			DP[j] = max(prev[j-1] + p, prev[j]);
		}

		for (int j = d+1; j <= D; j++) {
			DP[j] = DP[j - 1];
		}

		q.push(DP);
	}

	cout << q.front()[D];
}
