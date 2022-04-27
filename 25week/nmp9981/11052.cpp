#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
const int maxi = 1001;
int dp[maxi];//카드 i개일때 최대금액

//입력
void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> dp[i];
}

//카드 구매하기
void card() {
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			dp[i] = max(dp[i], dp[i - j] + dp[j]);//j번 카드 구매여부
		}
	}
	cout << dp[n];//출력
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	card();//카드 구매하기
	return 0;
}
