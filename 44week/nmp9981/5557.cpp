#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

int n;
const int maxi = 101;
ll A[maxi];//수열
ll dp[maxi][21];//등식의 개수

//입력
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) cin>>A[i];
	memset(dp, 0, sizeof(dp));//초기화
	dp[0][A[0]] = 1;
}
//등식의 개수
void Equals() {
	for (int i = 1; i < n - 1; i++) {//자릿수
		for (int j = 0; j < 21; j++) {//결과
			if (dp[i - 1][j] != 0) {
				if (j + A[i] <= 20) dp[i][j + A[i]] += dp[i - 1][j];//덧셈
				if (j - A[i] >=0) dp[i][j - A[i]] += dp[i - 1][j];//뺄셈
			}
		}
	}
}

int main(){
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	Equals();//등식의 개수
	cout << dp[n - 2][A[n - 1]];//출력
    return 0;
}
