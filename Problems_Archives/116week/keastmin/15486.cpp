#include <iostream>
using namespace std;
#define MAX 1500000

int N;
int days[MAX + 1];
int pays[MAX + 1];
long long dp[MAX + 1];
long long res = 0;

long long findMax(long long a, long long b) {
	if (a < b) return b;
	return a;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> days[i] >> pays[i];

		int targetDay = i + days[i] - 1;
		if (targetDay <= N) {
			dp[targetDay] = findMax(dp[targetDay], dp[i - 1] + pays[i]);
			res = findMax(res, dp[targetDay]);
		}
		dp[i] = findMax(dp[i - 1], dp[i]);
	}

	cout << res << '\n';

	return 0;
}
