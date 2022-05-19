#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int test,n;
const int maxi = 501;
const int inf = 1e+9;
int file[maxi];//파일
int sum[maxi];//누적 합
int dp[maxi][maxi];//i~j까지의 비용

//초기화
void init() {
	memset(file, 0, sizeof(file));
	memset(sum, 0, sizeof(sum));
}

//입력
void input() {
	cin >> n;
	init();//초기화
	for (int i = 1; i <= n; i++) {
		cin >> file[i];
		sum[i] = sum[i - 1] + file[i];
	}
}

//파일 합치기
void file_add() {
	for (int s = 1; s <= n; s++) {//사이즈
		for (int i = 1; i <= n-s; i++) {//시작지점
			int j = i+s;//종료지점
			dp[i][j] = inf;
			for (int k = i; k < j; k++) {//i~j => i~k, k+1~j
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]+sum[j]-sum[i-1]);
			}
		}
	}
	cout << dp[1][n] << "\n";//출력
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> test;
	for (int t = 0; t < test; t++) {
		input();//입력
		file_add();//파일 합치기
	}
	return 0;
}
