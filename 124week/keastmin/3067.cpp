#include <iostream>
#include <vector>
using namespace std;

int T, N, M;
vector<int> arr;
vector<int> dp;

int main() {
	cin >> T;
	while (T--) {
		cin >> N;
		arr.assign(N + 1, 0);
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
		}
		cin >> M;
		dp.assign(M + 1, 0);
		dp[0] = 1;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (j - arr[i] >= 0) {
					dp[j] += dp[j - arr[i]];
				}
			}
		}

		cout << dp[M] << '\n';
	}

	return 0;
}
