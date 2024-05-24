#include<iostream>
#include<vector>

using namespace std;

void Dp(vector<vector<long long>> &dp , int i , vector<int> &arr) {
	for ( int t = 0; t < 21; t++ ) {
		int k1,k2;
		if ( dp[i + 1][t] > 0 ) {
			k1 = t - arr[i];
			k2 = t + arr[i];
			if ( k1 >= 0 )dp[i][k1] += dp[i + 1][t];
			if ( k2 <= 20 )dp[i][k2] += dp[i + 1][t];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	vector<vector<long long>> dp(N, vector<long long>(21,0));
	vector<int> arr(N);
	for ( int i = 0; i < N; i++ ) {
		cin >> arr[i];
	}
	int t = arr[N - 1] - arr[N - 2];
	if ( t >= 0 )dp[N - 2][t]++;
	t = arr[N - 1] + arr[N - 2];
	if ( t <= 20 )dp[N - 2][t]++;

	for ( int i = N-3; i >= 0; i-- ) {
		Dp(dp, i, arr);
	}
	long long res=0;
	/*for ( int i = 0; i < 21; i++ ) {
		res += dp[0][i];
	}*/
	res = dp[1][arr[0]];
	cout << res << endl;
	return 0;
}