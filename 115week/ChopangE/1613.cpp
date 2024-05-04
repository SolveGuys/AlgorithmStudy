#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int n, k,s;
	cin >> n >> k;
	vector<vector<bool>> dp(n + 1, vector<bool>(n + 1));
	for ( int i = 0; i < k; i++ ) {
		int a, b;
		cin >> a >> b;
		dp[a][b] = 1;
	}
	for ( int k = 1; k < n + 1; k++ ) {
		for ( int i = 1; i < n + 1; i++ ) {
			if ( i == k )continue;
			for ( int j = 1; j < n + 1; j++ ) {
				if ( j == k || dp[i][j] ) continue;
				if ( dp[i][k] && dp[k][j] )dp[i][j] = 1;
			}
		}
	}


	cin >> s;
	for ( int i = 0; i < s; i++ ) {
		int a, b;
		cin >> a >> b;
		if ( dp[a][b] )cout << -1 << '\n';
		else if ( dp[b][a] )cout << 1 << '\n';
		else cout << 0 << '\n';
	}

	return 0;
}