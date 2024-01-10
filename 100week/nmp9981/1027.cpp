#include <iostream>
#include <algorithm>
using namespace std;

int n,ans;
double slope,new_slope;//기울기
const int maxi = 51;
const double inf = 2000000000.0;
int Height[maxi];//빌딩의 높이
int* p;

//입력
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> Height[i];
	p = Height;
}

//기울기
double gradient(int x1, int x2, int y1, int y2) {
	return (double)(y2 - y1) / (double)(x2 - x1);
}
//빌딩의 수 구하기
void building() {
	//기준 빌딩선택
	for (int i = 0; i < n; i++) {
		int cnt = 0;//빌딩 i에서 보이는 빌딩의 수
		//왼쪽
		slope = inf;
		for (int j = i - 1; j >= 0; j--) {
			//기울기가 더 작으면
			new_slope = gradient(i, j, *(p+i), *(p+j));
			if (slope > new_slope) {
				slope = new_slope;//기울기 갱신
				cnt++;
			}
		}
		//오른쪽
		slope = -inf;
		for (int j = i + 1; j < n; j++) {
			//기울기가 더 크면
			new_slope = gradient(i, j, *(p + i), *(p + j));
			if (slope < new_slope) {
				slope = new_slope;//기울기 갱신
				cnt++;
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans;//출력
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	building();//빌딩
	return 0;
}
