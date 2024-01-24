#include <iostream>
#include <cstring>
using namespace std;

int n,goal;
const int maxi = 10001;
const int Kind = 21;
int money[Kind];//동전 종류
int coinKind[Kind][maxi];//i번째 동전까지 했을때 j원을 만드는 횟수

//초기화
void init() {
	memset(money, 0, sizeof(money));
	memset(coinKind, 0, sizeof(coinKind));
}
//입력
void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> money[i];
	cin >> goal;
}
//동전
void Coin() {
	//첫번째 코인
	for (int j = 0; j <= goal; j++) {
		if ((j % money[1]) == 0) coinKind[1][j] = 1;
	}
	//i번째까지의 동전으로 j원을 만드는 경우의 수
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= goal; j++) {
			if (j < money[i]) coinKind[i][j] = coinKind[i - 1][j];//돈이 모자람
			else coinKind[i][j] = coinKind[i][j - money[i]] + coinKind[i - 1][j];//money[i]사용 여부
		}
	}
	cout << coinKind[n][goal] << "\n";
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		init();//초기화
		input();//입력
		Coin();//동전
	}
	return 0;
}
