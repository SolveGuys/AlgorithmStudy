#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, K;



int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	vector<vector<int>> Time(2, vector<int>(N + 1));
	vector<vector<int>> Money(2, vector<int>(N + 1));
	vector<vector<int>> dp(N + 1, vector<int>(K + 1,0));
	for ( int i = 1; i < N+1; i++ ) {
		cin >> Time[0][i] >> Money[0][i] >> Time[1][i] >> Money[1][i];
	}
	int min_t = 0; 
	
	for ( int i = 1; i < N + 1; i++ ) {

		for ( int j = min_t + Time[0][i]; j <= K; j++ ) {
			dp[i][j] = dp[i - 1][j - Time[0][i]] + Money[0][i];
		}
		for ( int j = min_t + Time[1][i]; j <= K; j++ ) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j - Time[1][i]] + Money[1][i]);
		}
		min_t += min(Time[0][i], Time[1][i]);
	}
	cout << dp[N][K] << endl;
	

	return 0;
}