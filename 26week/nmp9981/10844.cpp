#include <iostream>
using namespace std;

int n;
const int maxi = 101;
const int mod = 1e+9;
int dp[maxi][10];//자릿수i, 끝자리 j의 개수

//입력
void input() {
	cin >> n;
	dp[1][0] = 0;
	for (int i = 1; i <= 9; i++) dp[1][i] = 1;
}

//계단 수 
void StairNum() {
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			//끝자리가 0일때, 10
			if (j == 0) {
				dp[i][j] = dp[i - 1][1] % mod;
			}//끝자리가 9일때, 89
			else if (j == 9) {
				dp[i][j] = dp[i - 1][8] % mod;
			}
			else {
				dp[i][j] = (dp[i - 1][j + 1] + dp[i - 1][j - 1]) % mod;
			}
		}
	}
	int ans = 0;
	for (int j = 0; j <= 9; j++) {
		ans += dp[n][j];
		ans %= mod;
	}
	cout << ans;
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	StairNum();//계단 수
	return 0;
}
