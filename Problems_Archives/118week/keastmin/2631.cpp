#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	vector<int> arr;
	vector<int> dp;
	int largeCnt = 0;
	cin >> N;
	arr.resize(N + 1, 0);
	dp.resize(N + 1, 1);

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		largeCnt = max(largeCnt, dp[i]);
	}

	cout << N - largeCnt << '\n';

	return 0;
}
