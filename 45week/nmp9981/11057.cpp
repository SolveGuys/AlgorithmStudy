#include <iostream>
using namespace std;

int n;
const int maxi = 1001; const int digitMaxi = 10; const int mod = 10007;
int dp[maxi][digitMaxi];//(자릿수, 끝자리수)일때 오르막수 개수

//오르막 수
void ClimbNum() {
	//초기화
	int sum = 0;
	for (int i = 0; i < 10; i++) dp[1][i] = 1;
	//오르막수 개수 구하기
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= mod;
			}
		}
	}
	//총합 구하기
	for (int i = 0; i < 10; i++) sum+=dp[n][i];
	cout << sum%mod;
}

int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;//입력
	ClimbNum();//오르막 수
	return 0;
}
