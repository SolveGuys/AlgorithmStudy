#include <iostream>
#include <vector>
using namespace std;

int n;
const int maxi = 1001;
int A[maxi];//수열
int reA[maxi];//A수열을 거꾸로
int dpA[maxi];//증가 수열 길이
int redpA[maxi];//감소 수열 길이

//max
inline int max(int x, int y) {
	return x > y ? x : y;
}

//입력
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		reA[n - 1 - i] = A[i];//거꾸로 입력
	}
}

//바이토닉 수열
void Bitonic() {
	//기본적으로 최소길이 1이다.
	for (int i = 0; i < n; i++) {
		dpA[i] = 1; redpA[i] = 1;
	}
	//바이토닉 수열
	for (int i = 0; i < n; i++) {//기준점
		for (int j = 0; j < i; j++) {
			//증가
			if(A[i] > A[j]) dpA[i] = max(dpA[i], dpA[j] + 1);
			//감소
			if (reA[i] > reA[j]) redpA[i] = max(redpA[i], redpA[j] + 1);
		}
	}
	//길이 구하기
	int ans = 1;
	for (int i = 0; i < n; i++) ans = max(ans, dpA[i] + redpA[n-1-i] - 1);
	cout << ans;
}

int main(){
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	Bitonic();//바이토닉 수열
    return 0;
}
