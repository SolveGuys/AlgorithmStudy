#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>

using namespace std;

int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	vector<pair<int, int>> day(N + 1);
	vector <long long > DP(N + 1);
	fill(DP.begin(), DP.end(), 0);

	for (int i = 1; i <= N; i++) {
		int T, P;
		cin >> T >> P;
		day[i].first = T;
		day[i].second = P;
	}

	for (int i = 1; i <= N; i++) {
		int T, P;
		tie(T, P) = day[i];
		DP[i] = max(DP[i - 1], DP[i]);
		if (i + T - 1 > N) continue;
		DP[i + T - 1] = max(DP[i + T - 1], DP[i - 1] + P);
	}
	
	cout << DP[N];
}