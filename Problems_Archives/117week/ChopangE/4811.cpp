#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N;

vector<vector<long long>> dp(31, vector<long long>(31,0));


long long DFS(int f,int l) {
	if ( f == l || f == 0 )return dp[f][l];
	else if ( f < l ) {
		if ( dp[f][l] > 0 )return dp[f][l];
		dp[f][l] = DFS(f - 1, l) + DFS(f, l - 1);
		return dp[f][l];
	}
	

}

void Cal(int i) {
	if ( i >= 31 )return;
	dp[i][i] = DFS(i- 1, i);
	Cal(i + 1);
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	for ( int i = 1; i < 31; i++ ) {
		dp[0][i] = 1;
	}
	dp[1][1] = 1;
	Cal(2);
	int N;
	while ( 1 ) {
		cin >> N;
		if ( N == 0 )break;
		cout << dp[N][N] << endl;
	}
	return 0;
}