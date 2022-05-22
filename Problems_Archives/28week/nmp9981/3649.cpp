#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n,x,t;
const int maxi = 1000001;
const int inf = 200000001;
const int nano = 10000000;//단위 변환 상수
int lego[maxi];//조각의 길이

//입력
void input() {
	memset(lego, 0, sizeof(lego));//초기화
	for (int i = 0; i < n; i++) cin >> lego[i];
	sort(lego, lego+n);//정렬
}

//구멍 막기
void hole() {
	int left = 0;
	int right = n - 1;
	while (left < right) {
		if (lego[left] + lego[right] == x*nano) {//일치
			cout << "yes " <<lego[left]<<" "<<lego[right] << "\n";
			return;
		}
		else if (lego[left] + lego[right] < x*nano) {//모자르면 더 길게
			left++;
		}
		else {//넘치면 더 짧게
			right--;
		}
	}
	cout << "danger" << "\n";//맞는 구멍이 없음
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	while (cin >> x>>n) {//구멍의 너비를 EOP로 받는다.
		input();//입력
		hole();//구멍 막기
		t++;//테스트 번호 증가
	}
	return 0;
}
