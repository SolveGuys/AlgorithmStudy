#include <iostream>
using namespace std;

int n, k;
const int maxi = 401;
const int mod = 1e+9;
int dp[maxi][maxi];//조합값담는 배열

//입력
void input() {
	cin >> n>>k;
}

//nCm
void combi() {
	dp[1][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i < maxi; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) dp[i][j] = 1;
			else dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1])%mod;
		}
	}
}

int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	combi();//조합 구하기
	cout << dp[k + n - 1][n];//경우의수는 kHn = k+n-1Cn
	return 0;
}
