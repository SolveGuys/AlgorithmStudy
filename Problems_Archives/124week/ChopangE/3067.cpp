#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for ( int index = 0; index < T; index++ ) {
		int N, K;
		cin >> N;
		vector<int> coin(N);
		for ( int j = 0; j < N; j++ ) {
			cin >> coin[j];
		}
		cin >> K;
		vector<vector<int>> dp(N, vector<int>(K+1, 0));
		for ( int i = 0; i < N; i++ ) {
			dp[i][0] = 1;
		}
		for ( int j = 1; j < K+1; j++ ) {
			if ( j % coin[0] == 0 )dp[0][j] = 1;
		}
		for ( int i = 1; i < N; i++ ) {
			for ( int j = 1; j < K + 1; j++ ) {
				if ( coin[i] > j ) {
					dp[i][j] = dp[i - 1][j];
					continue;
				}
				dp[i][j] = dp[i][j - coin[i]] + dp[i - 1][j];
				
			}
		}
		cout << dp[N - 1][K] << endl;
	}

	return 0;
}