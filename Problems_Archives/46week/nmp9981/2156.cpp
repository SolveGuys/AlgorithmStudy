#include <iostream>
using namespace std;

int n;
const int maxi = 10001;
int amountGrape[maxi];//포도주의 양
int csumGrape[maxi];//최대 시식 포도주의 양

//max
int inline max(int x, int y) {
	return x > y ? x : y;
}
//입력
void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> amountGrape[i];
}
//포도주의 양
void Grape() {
	//초기값
	csumGrape[1] = amountGrape[1];
	csumGrape[2] = amountGrape[1]+amountGrape[2];
	//dp
	for (int i = 3; i <= n; i++) {
		csumGrape[i] = max(csumGrape[i - 1], max(csumGrape[i - 2] + amountGrape[i], csumGrape[i - 3] + amountGrape[i] + amountGrape[i - 1] ));
	}
}

int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	Grape();//최대 시식 가능한 포도주의 양 구하기
	cout << csumGrape[n];//출력
	return 0;
}
