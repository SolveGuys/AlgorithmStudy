#include <iostream>
using namespace std;

int n;
const int maxi = 100001;
int dp[maxi];

//최솟값
inline int min(int x, int y) {
	return x > y ? y : x;
}

//제곱수
void square() {
	dp[1] = 1;//초기값
	for (int i = 2; i <= n; i++) {
		dp[i] = i;//초기화
		int j = 1;
		while(i>=j*j){
			dp[i] = min(dp[i - j * j]+1, dp[i]);//j*j개수(1개)
			j++;
		}
	}
	cout << dp[n];//출력
}
int main(){
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;//입력
	square();//제곱수
    return 0;
}
