#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<long long>> dp;
vector<int> arr;


int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;
	arr.resize(N + 1);
	dp.resize(N + 1, vector<long long>(21, 0));
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	// 첫번째 수는 그대로 사용하므로 경우의 수 1
	dp[1][arr[1]] = 1;

	for (int i = 2; i < N; i++) {
		for (int j = 0; j <= 20; j++) {
			// 이전 번째 수에서 j가 만들어지는 수인지 체크
			if (dp[i - 1][j] > 0) {

				// 만들어진다면 현재 번째 수를 더하거나 빼어 경우의 수 추가
				if (j + arr[i] <= 20) dp[i][j + arr[i]] += dp[i - 1][j];
				if (j - arr[i] >= 0) dp[i][j - arr[i]] += dp[i - 1][j];
			}
		}
	}

	// 문제를 잘 읽자. 등호를 통해 arr[N]값이 완성되는 수를 찾아야 한다.
	// 때문에 [N - 1]번째 수까지 이용해 arr[N]값이 완성되는 경우의 수를 출력한다.
	cout << dp[N - 1][arr[N]] << '\n';

	return 0;
}
