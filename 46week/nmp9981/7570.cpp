#include <iostream>
using namespace std;

int n,x;
const int maxi = 1000001;
int child[maxi];//연속 최장 증가 수열의 길이

//max
int inline max(int x, int y) {
	return x > y ? x : y;
}
//연속 LIS 구하기
void continueLIS() {
	cin >> n;
	int maxLen = 1;//길이
	for (int i = 0; i < n; i++) {
		cin >> x;
		child[x] = child[x - 1] + 1;//연속이어야하므로 이전 결과에서 1을 더해준다
		maxLen = max(child[x], maxLen);//길이 갱신
	}
	cout << n - maxLen;//출력
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	continueLIS();//연속 LIS 구하기
	return 0;
}
