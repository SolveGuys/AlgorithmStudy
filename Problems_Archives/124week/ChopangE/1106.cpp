#include<iostream>
#include<vector>

using namespace std;

typedef pair<int, int> ii;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int C, N;
	cin >> C >> N;
	int max_t = 0;
	vector<ii> arr(N);
	
	for ( int i = 0; i < N; i++ ) {
		cin >> arr[i].first >> arr[i].second;
		max_t = max(max_t, arr[i].second);
	}
	int width = C + max_t;
	vector<vector<int>> dp(N, vector<int>(width, 10000000));

	for ( int i = 0; i < N; i++ ) {
		dp[i][0] = 0;
	}

	for ( int i = 1; i < width; i++ ) {
		if ( i % arr[0].second == 0 ) dp[0][i] = (i / arr[0].second) * arr[0].first;
	}
	
	for ( int i = 1; i < N; i++ ) {
		for ( int j = 1; j < width; j++ ) {
			if ( j >= arr[i].second ) {
				dp[i][j] = min(dp[i][j - arr[i].second] + arr[i].first, dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	
	int min_t = 10000000;
	for ( int i = C; i < width; i++ ) {
		min_t = min(min_t, dp[N - 1][i]);
	}
	cout << min_t << endl;
	return 0;
}