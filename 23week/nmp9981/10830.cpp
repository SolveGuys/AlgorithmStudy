#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> Matrix;

ll n,b;
const int mod = 1000;
const int maxi = 5;
Matrix A(maxi, vector<int>(maxi));;//행렬 A
Matrix ans(maxi,vector<int>(maxi));//정답 행렬

//입력
void input() {
	cin >> n>>b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
		}
	}
}
//행렬의 곱셈
Matrix mul(Matrix p, Matrix q) {
	Matrix temp(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				temp[i][j] += (p[i][k] * q[k][j]);
				temp[i][j] %= mod;
			}
		}
	}
	return temp;
}

//행렬 거듭제곱
Matrix div(ll x) {
	if (x == 1) return A;

	ll y = x / 2;
	Matrix f = div(x/2);
	//홀짝수 차수에 따라
	if (x % 2 == 0) {
		return mul(f, f);
	}else {
		return mul(mul(f, f), A);
	}
}
//출력
void output() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j]%mod << " ";//1000으로 나눈 나머지를 출력
		}
		cout << "\n";
	}
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	ans = div(b);//행렬 거듭제곱
	output();//출력
	return 0;
}
