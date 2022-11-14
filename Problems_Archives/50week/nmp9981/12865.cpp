#include <iostream>
using namespace std;

int n, k;
const int maxi = 101;
const int weightMaxi = 100001;
int weight[maxi];//무게
int value[maxi];//가치
int dp[maxi][weightMaxi];//i번 물건까지 샀을때 j무게에서의 가치

//max
inline int max(int x, int y) {
	return x > y ? x : y;
}
//입력
void input() {
	cin >> n>>k;
	for (int i = 1; i <= n; i++) cin >> weight[i] >> value[i];
}
//가방에 물건 넣기
void bag() {
	for (int i = 1; i <= n; i++) {//i번 물건까지 샀을때
		for (int j = 1; j <= k; j++) {//j무게에서의 가치
			if (j < weight[i]) dp[i][j] = dp[i - 1][j];//넣을 수 없다면
			else dp[i][j] = max(dp[i-1][j], dp[i - 1][j - weight[i]] + value[i]);//물건을 넣는가? 그대로인가?
		}
	}
	cout << dp[n][k];
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	bag();//가방에 물건 넣기
	return 0;
}
