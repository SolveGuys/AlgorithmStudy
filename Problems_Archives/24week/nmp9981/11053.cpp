#include <iostream>
#include <algorithm>
using namespace std;

int n,maxi_cnt;
const int maxi = 1001;
int A[maxi];//수열 A
int dp[maxi];//최장 증가하는 부분 수열 길이

//입력
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		dp[i] = 1;//기본적으로 길이가 1
	}
}
//가장 긴 증가하는 부분수열
void LIS() {
	maxi_cnt = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j]) dp[i] = max(dp[j] + 1, dp[i]);//그대로 유지 or 갱신
		}
		maxi_cnt = max(dp[i], maxi_cnt);//최대 길이 갱신
	}
	cout << maxi_cnt;//출력
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	LIS();//가장 긴 증가하는 부분수열
	return 0;
}
